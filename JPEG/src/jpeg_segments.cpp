#include "jpeg_segments.hpp"

// Function to convert a YCbCr pixel to RGB
RgbPixel YCbCrToRgb(const YCbCrPixel& ycbcr) {
  RgbPixel rgb;
  rgb.r = ycbcr.y + 1.4022f * ycbcr.cr;
  rgb.g = ycbcr.y - 0.7145f * ycbcr.cr - 0.3456f * ycbcr.cb;
  rgb.b = ycbcr.y + 1.7710f * ycbcr.cb;
  return rgb;
}

// Function to convert an RGB pixel to YCbCr
YCbCrPixel RgbToYCbCr(const RgbPixel& rgb) {
  YCbCrPixel ycbcr;
  ycbcr.y  =  0.2126f * rgb.r + 0.7152f * rgb.g + 0.0722f * rgb.b;
  ycbcr.cb = -0.1146f * rgb.r - 0.3854f * rgb.g + 0.5000f * rgb.b;
  ycbcr.cr =  0.5000f * rgb.r - 0.4542f * rgb.g - 0.0458f * rgb.b;
  return ycbcr;
}

// Reduces the resolution of the chroma data in a YCbCr image by a factor of n
std::vector<YCbCrPixel> reduceChromaResolution(const std::vector<YCbCrPixel>& image, int n) {
    std::vector<YCbCrPixel> reduced(image.size());  // Allocate memory for the reduced resolution image
    for (std::size_t i = 0; i < image.size(); i++) {
        const YCbCrPixel& pixel = image[i];
        YCbCrPixel& reduced_pixel = reduced[i];
        reduced_pixel.y = pixel.y;
        reduced_pixel.cb = std::round(pixel.cb / n) * n;
        reduced_pixel.cr = std::round(pixel.cr / n) * n;
    }
    return reduced;
}

// Calculates the discrete cosine transform of 8x8 blocks in a YCbCr image
std::vector<YCbCrPixel> calculateDCT(const std::vector<YCbCrPixel>& image, int width, int height) {
    std::vector<YCbCrPixel> dct(image.size());  // Allocate memory for the DCT image
    for (int y = 0; y < height; y += 8) {
        for (int x = 0; x < width; x += 8) {
            for (int v = 0; v < 8; v++) {
                for (int u = 0; u < 8; u++) {
                    float y_sum = 0.0;
                    float cb_sum = 0.0;
                    float cr_sum = 0.0;
                    for (int i = 0; i < 8; i++) {
                        for (int j = 0; j < 8; j++) {
                            float ci = (i == 0) ? 1.0 / sqrt(2) : 1.0;
                            float cj = (j == 0) ? 1.0 / sqrt(2) : 1.0;
                            float y_pixel = image[(y + i) * width + (x + j)].y;
                            float cb_pixel = image[(y + i) * width + (x + j)].cb;
                            float cr_pixel = image[(y + i) * width + (x + j)].cr;
                            y_sum += ci * cj * y_pixel * cos((M_PI * i * (2 * v + 1)) / 16.0) * cos((M_PI * j * (2 * u + 1)) / 16.0);
                            cb_sum += ci * cj * cb_pixel * cos((M_PI * i * (2 * v + 1)) / 16.0) * cos((M_PI * j * (2 * u + 1)) / 16.0);
                            cr_sum += ci * cj * cr_pixel * cos((M_PI * i * (2 * v + 1)) / 16.0) * cos((M_PI * j * (2 * u + 1)) / 16.0);
                        }
                    }
                }
            }
        }
    }
    return dct;
}

// Quantizes the amplitudes of frequencies in a YCbCr image
std::vector<YCbCrPixel> quantize(const std::vector<YCbCrPixel>& dct, int width, int height, const std::array<std::array<int, 8>, 8> quantization_matrix) {
    std::vector<YCbCrPixel> quantized(dct.size());  // Allocate memory for the quantized image
    for (int y = 0; y < height; y += 8) {
        for (int x = 0; x < width; x += 8) {
            for (int v = 0; v < 8; v++) {
                for (int u = 0; u < 8; u++) {
                    float y_quantized = std::roundf(dct[(y + v) * width + (x + u)].y / quantization_matrix[v][u]);
                    float cb_quantized = std::roundf(dct[(y + v) * width + (x + u)].cb / quantization_matrix[v][u]);
                    float cr_quantized = std::roundf(dct[(y + v) * width + (x + u)].cr / quantization_matrix[v][u]);
                    quantized[(y + v) * width + (x + u)].y = y_quantized;
                    quantized[(y + v) * width + (x + u)].cb = cb_quantized;
                    quantized[(y + v) * width + (x + u)].cr = cr_quantized;
                }
            }
        }
    }
    return quantized;
}

// Generates a quantization matrix with a given quality factor
std::array<std::array<int, 8>, 8> generateQuantizationMatrix(int quality_factor) {
    std::array<std::array<int, 8>, 8> quantization_matrix = {};
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int value = (i == 0 || j == 0) ? 8 : 16;
            quantization_matrix[i][j] = value * quality_factor;
        }
    }
    return quantization_matrix;
}

// Compresses a quantized YCbCr image using the Huffman coding algorithm
std::vector<uint8_t> compressQuantizedImage(const std::vector<YCbCrPixel>& quantized) {
    // Build a frequency table for the quantized image
    std::map<YCbCrPixel, int> frequency_table;
    for (const YCbCrPixel& pixel : quantized) {
        frequency_table[pixel]++;
    }

    // Build a Huffman tree from the frequency table
    HuffmanNode<YCbCrPixel>* root = HuffmanTree<YCbCrPixel>::build(frequency_table);

    // Assign codes to each value in the frequency table
    std::map<YCbCrPixel, std::vector<bool>> codes;
    std::vector<bool> prefix;
    HuffmanTree<YCbCrPixel>::assignCodes(root, codes, prefix);

    // Compress the quantized image using the Huffman tree and frequency table
    return HuffmanTree<YCbCrPixel>::compress(quantized, codes);
}

// Decompresses a quantized YCbCr image using the Huffman coding algorithm
std::vector<unsigned char> decompressQuantizedImage(const std::vector<unsigned char>& compressed, int width, int height) {
    // Build a frequency table for the quantized image
    std::map<unsigned char, int> frequency_table;
    for (const unsigned char& pixel : compressed) {
        frequency_table[pixel]++;
    }

    // Build a Huffman tree from the frequency table
    HuffmanNode<unsigned char>* root = HuffmanTree<unsigned char>::build(frequency_table);

    // Decompress the quantized image using the Huffman tree
    return HuffmanTree<unsigned char>::decompress(compressed, root);
}

// Calculates the reverse DCT of a 8x8 block of a YCbCr image
std::array<std::array<float, 8>, 8> reverseDCTBlock(const std::array<std::array<float, 8>, 8>& block) {
    std::array<std::array<float, 8>, 8> reversed;  // Allocate memory for the reversed DCT block
    for (int u = 0; u < 8; u++) {
        for (int v = 0; v < 8; v++) {
            float sum = 0.0f;
            for (int x = 0; x < 8; x++) {
                for (int y = 0; y < 8; y++) {
                    sum += block[x][y] * cos((2 * x + 1) * u * M_PI / 16) * cos((2 * y + 1) * v * M_PI / 16);
                }
            }
            reversed[u][v] = sum * (u == 0 ? 1.0f / sqrt(2) : 1.0f) * (v == 0 ? 1.0f / sqrt(2) : 1.0f);
        }
    }
    return reversed;
}

// Calculates the reverse DCT of a YCbCr image
std::vector<YCbCrPixel> reverseDCT(const std::vector<YCbCrPixel>& ycbcr) {
    std::vector<YCbCrPixel> reversed;  // Allocate memory for the reversed DCT image
    int width = sqrt(ycbcr.size());  // Assume the image is a square
    for (std::vector<YCbCrPixel>::size_type i = 0; i < ycbcr.size(); i += 64) {
        std::array<std::array<float, 8>, 8> block = {{{0.0f}}};  // Allocate memory for the 8x8 block
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                block[x][y] = ycbcr[i + x + y * width].y;  // Only operate on the Y component
            }
        }
        block = reverseDCTBlock(block);
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                reversed.push_back({block[x][y], ycbcr[i + x + y * width].cb, ycbcr[i + x + y * width].cr});
            }
        }
    }
    return reversed;
}

// Reverses the reduction of the resolution of the chroma data by a factor of n
std::vector<YCbCrPixel> reverseChromaResolutionReduction(const std::vector<YCbCrPixel>& ycbcr, int n) {
    std::vector<YCbCrPixel> reversed;  // Allocate memory for the reversed image
    int width = sqrt(ycbcr.size());  // Assume the image is a square
    for (std::vector<YCbCrPixel>::size_type i = 0; i < ycbcr.size(); i += 64) {
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                YCbCrPixel pixel = ycbcr[i + x + y * width];
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < n; k++) {
                        reversed.push_back({pixel.y, pixel.cb, pixel.cr});
                    }
                }
            }
        }
    }
    return reversed;
}
