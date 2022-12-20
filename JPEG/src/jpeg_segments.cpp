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

std::vector<YCbCrPixel> reduceChromaResolution(const std::vector<YCbCrPixel>& image, int n) {
    std::vector<YCbCrPixel> reduced(image.size());

    for (std::size_t i = 0; i < image.size(); i++) {
        const YCbCrPixel& pixel = image[i];
        YCbCrPixel& reduced_pixel = reduced[i];
        reduced_pixel.y = pixel.y;
        reduced_pixel.cb = std::round(pixel.cb / n) * n;
        reduced_pixel.cr = std::round(pixel.cr / n) * n;
    }

    return reduced;
}

std::vector<YCbCrPixel> increaseChromaResolution(const std::vector<YCbCrPixel>& image, int width, int height, int n) {
    std::vector<YCbCrPixel> reversed;

    for (std::vector<YCbCrPixel>::size_type i = 0; i < image.size(); i += 64) {
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                YCbCrPixel pixel = image[i + x + y * width];
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

std::vector<YCbCrPixel> calculateDCT(const std::vector<YCbCrPixel>& image, int width, int height) {
    std::vector<YCbCrPixel> dct(image.size());

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

std::vector<YCbCrPixel> reverseDCT(const std::vector<YCbCrPixel>& image, int width, int height) {
  std::vector<YCbCrPixel> result(image.size());
  //
  return result;
}

std::vector<YCbCrPixel> quantize(const std::vector<YCbCrPixel>& dct, int width, int height, const std::array<std::array<int, 8>, 8>& quantization_matrix) {
    std::vector<YCbCrPixel> quantized(dct.size());

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

std::vector<unsigned char> compressQuantizedImage(const std::vector<YCbCrPixel>& data) {
  std::vector<unsigned char> result;

  std::vector<unsigned char> raw_data;
  for(std::vector<YCbCrPixel>::size_type i = 0; i < data.size(); i++) {
    YCbCrPixel pixel = data[i];
    std::vector<unsigned char> vec = pixel.data();
    for(std::vector<unsigned char>::size_type j = 0; j < vec.size(); j++) {
      raw_data.push_back(vec[j]);
    }
  }
  HuffmanTree<unsigned char> tree;
  std::vector<unsigned char> compressed_data = tree.compress(raw_data);

  return result;
}

std::vector<YCbCrPixel> decompressQuantizedImage(const std::vector<unsigned char>& data, int width, int height)
{
  std::vector<YCbCrPixel> result;

  HuffmanTree<unsigned char> tree;
  std::vector<unsigned char> raw_data = tree.decompress(data);
  for(std::vector<unsigned char>::size_type i = 0; i < raw_data.size(); i += 3) {
    YCbCrPixel pixel = {raw_data[i], raw_data[i + 1], raw_data[i + 2]};
    result.push_back(pixel);
  }

  return result;
}
