#ifndef JPEG_H
#define JPEG_H

#include "../../common/matrix.hpp"
#include "../../common/pixel.hpp"
#include "../../common/huffman.hpp"

#include <fstream>
#include <cmath>

void reduce_resolution_chrome_data(std::vector<std::vector<YCbCrPixel>>& ycbcr, int factor);
void increase_resolution_chrome_data(std::vector<std::vector<YCbCrPixel>>& ycbcr, int factor);

void dct(std::vector<std::vector<YCbCrPixel>>& ycbcr);
void idct(std::vector<std::vector<YCbCrPixel>>& ycbcr);

void quantize(std::vector<std::vector<YCbCrPixel>>& ycbcr, std::vector<std::vector<int>>& quantization_table);
void dequantize(std::vector<std::vector<YCbCrPixel>>& ycbcr, std::vector<std::vector<int>>& quantization_table);

int getBlockCount(std::vector<std::vector<YCbCrPixel>>& ycbcr);
void getBlock(std::vector<std::vector<YCbCrPixel>>& ycbcr, int block_num, std::vector<std::vector<YCbCrPixel>>& block);
void generate_quantization_table(int quality, std::vector<std::vector<int>>& quantization_table);

class JPEG {
protected:
  Matrix<RgbPixel> pixels;
public:
  virtual void read(std::string filename) = 0;
  virtual void write(std::string filename) = 0;

  virtual int getWidth() = 0;
  virtual int getHeight() = 0;

  std::vector<float> toArray();
};

#endif
