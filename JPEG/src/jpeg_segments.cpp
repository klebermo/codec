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
        reduced[i].y = pixel.y;
        reduced[i].cb = pixel.cb / n;
        reduced[i].cr = pixel.cr / n;
    }

    return reduced;
}

std::vector<YCbCrPixel> increaseChromaResolution(const std::vector<YCbCrPixel>& image, int n) {
    std::vector<YCbCrPixel> reversed(image.size());

    for (std::size_t i = 0; i < image.size(); i++) {
        const YCbCrPixel& pixel = image[i];
        reversed[i].y = pixel.y;
        reversed[i].cb = pixel.cb * n;
        reversed[i].cr = pixel.cr * n;
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

  for (int y = 0; y < height; y += 8) {
    for (int x = 0; x < width; x += 8) {
      for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
          float sumY = 0.0, sumCb = 0.0, sumCr = 0.0;
          for (int u = 0; u < 8; u++) {
            for (int v = 0; v < 8; v++) {
              float cu = (u == 0) ? 1.0 / sqrt(2.0) : 1.0;
              float cv = (v == 0) ? 1.0 / sqrt(2.0) : 1.0;
              float pixelY = image[(y + u) * width + (x + v)].y;
              float pixelCb = image[(y + u) * width + (x + v)].cb;
              float pixelCr = image[(y + u) * width + (x + v)].cr;
              float cosineY = cos((2 * i + 1) * u * M_PI / 16.0) * cos((2 * j + 1) * v * M_PI / 16.0);
              float cosineCb = cos((2 * i + 1) * u * M_PI / 16.0) * cos((2 * j + 1) * v * M_PI / 16.0);
              float cosineCr = cos((2 * i + 1) * u * M_PI / 16.0) * cos((2 * j + 1) * v * M_PI / 16.0);
              sumY += cu * cv * pixelY * cosineY;
              sumCb += cu * cv * pixelCb * cosineCb;
              sumCr += cu * cv * pixelCr * cosineCr;
            }
          }
          result[(y + i) * width + (x + j)].y = sumY / 4.0;
          result[(y + i) * width + (x + j)].cb = sumCb / 4.0;
          result[(y + i) * width + (x + j)].cr = sumCr / 4.0;
        }
      }
    }
  }

  return result;
}

/*
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

std::vector<YCbCrPixel> dequantize(const std::vector<YCbCrPixel>& data, int width, int height, const std::array<std::array<int, 8>, 8>& quantization_matrix) {
    std::vector<YCbCrPixel> result(data.size());
    return result;
}
*/

std::vector<std::vector<int>> generateQuantizationMatrix(int size) {
  // The quantization matrix for JPEG compression is based on the following formula:
  // Q[i][j] = (1 + i + j) * K / (size + 1), where K is a constant chosen to scale the matrix.
  // A common value for K is 8.

  std::vector<std::vector<int>> matrix(size, std::vector<int>(size));
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      matrix[i][j] = (1 + i + j) * 8 / (size + 1);
    }
  }

  return matrix;
}

// Assume that the input image is stored in a 2D vector of integers called "image",
// and that the size of the image is stored in a pair of integers called "size".
// Also assume that the quantization matrix is stored in a 2D vector of integers called "matrix".
std::vector<YCbCrPixel> quantizeImage(std::vector<YCbCrPixel>& image, int width, int height, std::vector<std::vector<int>> matrix) {
    std::vector<YCbCrPixel> result;

    int index = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            YCbCrPixel pixel;
            // Quantize the Y component using the quantization matrix.
            pixel.y = std::round(image[index].y / matrix[i % matrix.size()][j % matrix.size()]);

            // Quantize the Cb and Cr components using the same quantization matrix.
            pixel.cb = std::round(image[index].cb / matrix[i % matrix.size()][j % matrix.size()]);
            pixel.cr = std::round(image[index].cr / matrix[i % matrix.size()][j % matrix.size()]);

            result.push_back(pixel);
        }
    }

    return result;
}

// Assume that the input image is stored in a 2D vector of integers called "image",
// and that the size of the image is stored in a pair of integers called "size".
// Also assume that the quantization matrix is stored in a 2D vector of integers called "matrix".
std::vector<YCbCrPixel> dequantizeImage(std::vector<YCbCrPixel>& image, int width, int height, std::vector<std::vector<int>> matrix) {
    std::vector<YCbCrPixel> result;

    int index = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            YCbCrPixel pixel;
            // Dequantize the Y component using the quantization matrix.
            pixel.y = image[index].y * matrix[i % matrix.size()][j % matrix.size()];

            // Dequantize the Cb and Cr components using the same quantization matrix.
            pixel.cb = image[index].cb * matrix[i % matrix.size()][j % matrix.size()];
            pixel.cr = image[index].cr * matrix[i % matrix.size()][j % matrix.size()];

            result.push_back(pixel);
        }
    }

    return result;
}

std::vector<unsigned char> encodeImage(const std::vector<YCbCrPixel>& data, std::map<unsigned char, std::vector<bool>>& huffman_table) {
  std::vector<unsigned char> raw_data;

  for(std::vector<YCbCrPixel>::size_type i = 0; i < data.size(); i++) {
    YCbCrPixel pixel = data[i];

    std::vector<unsigned char> vec;
    unsigned char y = static_cast<unsigned char>(pixel.y);
    unsigned char cb = static_cast<unsigned char>(pixel.cb);
    unsigned char cr = static_cast<unsigned char>(pixel.cr);
    vec.push_back(y);
    vec.push_back(cb);
    vec.push_back(cr);

    for(std::vector<unsigned char>::size_type j = 0; j < vec.size(); j++) {
      raw_data.push_back(vec[j]);
    }
  }

  HuffmanTree<unsigned char> tree;
  return huffman_encode(raw_data, huffman_table);
}

std::vector<YCbCrPixel> decodeImage(const std::vector<unsigned char>& data, std::map<unsigned char, std::vector<bool>>& huffman_table, int width, int height) {
  std::vector<YCbCrPixel> result;

  HuffmanTree<unsigned char> tree;
  std::vector<unsigned char> raw_data = huffman_decode(data, huffman_table);

  for(std::vector<unsigned char>::size_type i = 0; i < raw_data.size(); i += 3) {
    float y = static_cast<float>(raw_data[i]);
    float cb = static_cast<float>(raw_data[i + 1]);
    float cr = static_cast<float>(raw_data[i + 2]);

    YCbCrPixel pixel;
    pixel.y = y;
    pixel.cb = cb;
    pixel.cr = cr;

    result.push_back(pixel);
  }

  return result;
}
