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

// Function to reduce the resolution of the chroma data
void reduce_resolution_chrome_data(std::vector<std::vector<YCbCrPixel>>& ycbcr, int factor) {
  for(std::vector<YCbCrPixel>::size_type i=0; i<ycbcr.size(); i++) {
    for(std::vector<YCbCrPixel>::size_type j=0; j<ycbcr[0].size(); j++) {
      YCbCrPixel pixel = ycbcr[i][j];
      pixel.cb /= factor;
      pixel.cr /= factor;
      ycbcr[i][j] = pixel;
    }
  }
}

// Function to increase the resolution of the chroma data
void increase_resolution_chrome_data(std::vector<std::vector<YCbCrPixel>>& ycbcr, int factor) {
  for(std::vector<YCbCrPixel>::size_type i=0; i<ycbcr.size(); i++) {
    for(std::vector<YCbCrPixel>::size_type j=0; j<ycbcr[0].size(); j++) {
      YCbCrPixel pixel = ycbcr[i][j];
      pixel.cb *= factor;
      pixel.cr *= factor;
      ycbcr[i][j] = pixel;
    }
  }
}

// Function to perform the DCT on a vector of YCbCr pixels
void dct(std::vector<std::vector<YCbCrPixel>>& ycbcr) {
  int rows = ycbcr.size();
  int cols = ycbcr[0].size();

  for(int u=0; u<rows; u++) {
    for(int v=0; v<cols; v++) {
      float sumY = 0.0;
      float sumCb = 0.0;
      float sumCr = 0.0;
      for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
          float cu = (u == 0) ? 1.0f / sqrt(2.0f) : 1.0f;
          float cv = (v == 0) ? 1.0f / sqrt(2.0f) : 1.0f;
          float cos1 = cos((2.0f * i + 1.0f) * u * M_PI / (2.0f * rows));
          float cos2 = cos((2.0f * j + 1.0f) * v * M_PI / (2.0f * cols));
          sumY += ycbcr[i][j].y * cu * cv * cos1 * cos2;
          sumCb += ycbcr[i][j].cb * cu * cv * cos1 * cos2;
          sumCr += ycbcr[i][j].cr * cu * cv * cos1 * cos2;
        }
      }
      ycbcr[u][v].y = (1.0/4.0) * sumY * sqrt(2.0/rows) * sqrt(2.0/cols);
      ycbcr[u][v].cb = (1.0/4.0) * sumCb * sqrt(2.0/rows) * sqrt(2.0/cols);
      ycbcr[u][v].cr = (1.0/4.0) * sumCr * sqrt(2.0/rows) * sqrt(2.0/cols);
    }
  }
}

// Function to perform the inverse DCT on a vector of YCbCr pixels
void idct(std::vector<std::vector<YCbCrPixel>>& ycbcr) {
  int rows = ycbcr.size();
  int cols = ycbcr[0].size();

  for(int i=0; i<rows; i++) {
    for(int j=0; i<cols; j++) {
      float sumY = 0.0;
      float sumCb = 0.0;
      float sumCr = 0.0;
      for(int u = 0; u<rows; u++) {
        for(int v = 0; v<cols; v++) {
          float cu = (u == 0) ? 1.0f / sqrt(2.0f) : 1.0f;
          float cv = (v == 0) ? 1.0f / sqrt(2.0f) : 1.0f;
          float cos1 = cos((2.0f * i + 1.0f) * u * M_PI / (2.0f * rows));
          float cos2 = cos((2.0f * j + 1.0f) * v * M_PI / (2.0f * cols));
          sumY += ycbcr[u][v].y * cu * cv * cos1 * cos2;
          sumCb += ycbcr[u][v].cb * cu * cv * cos1 * cos2;
          sumCr += ycbcr[u][v].cr * cu * cv * cos1 * cos2;
        }
      }
      ycbcr[i][j].y = (1.0/4.0) * sumY * sqrt(2.0/rows) * sqrt(2.0/cols);
      ycbcr[i][j].cb = (1.0/4.0) * sumCb * sqrt(2.0/rows) * sqrt(2.0/cols);
      ycbcr[i][j].cr = (1.0/4.0) * sumCr * sqrt(2.0/rows) * sqrt(2.0/cols);
    }
  }
}

// Function to perform the quantization on a vector of YCbCr pixels
void quantize(std::vector<std::vector<YCbCrPixel>>& ycbcr, std::vector<std::vector<int>>& quantization_table) {
  int rows = ycbcr.size();
  int cols = ycbcr[0].size();

  for(int i=0; i<rows; i++) {
    for(int j=0; j<cols; j++) {
      ycbcr[i][j].y = ycbcr[i][j].y / quantization_table[0][0];
      ycbcr[i][j].cb = ycbcr[i][j].cb / quantization_table[1][1];
      ycbcr[i][j].cr = ycbcr[i][j].cr / quantization_table[2][2];
    }
  }
}

// Function to perform the dequantization on a vector of YCbCr pixels
void dequantize(std::vector<std::vector<YCbCrPixel>>& ycbcr, std::vector<std::vector<int>>& quantization_table) {
  int rows = ycbcr.size();
  int cols = ycbcr[0].size();

  for(int i=0; i<rows; i++) {
    for(int j=0; j<cols; j++) {
      ycbcr[i][j].y = ycbcr[i][j].y * quantization_table[0][0];
      ycbcr[i][j].cb = ycbcr[i][j].cb * quantization_table[1][1];
      ycbcr[i][j].cr = ycbcr[i][j].cr * quantization_table[2][2];
    }
  }
}

// Function to return the amount of 8x8 blocks in a vector of YCbCr pixels
int getBlockCount(std::vector<std::vector<YCbCrPixel>>& ycbcr) {
  int rows = ycbcr.size();
  int cols = ycbcr[0].size();
  int block_rows = rows / 8;
  int block_cols = cols / 8;
  int remainder_rows = rows % 8;
  int remainder_cols = cols % 8;
  int block_count = block_rows * block_cols;

  if(remainder_rows > 0) {
    block_count += block_cols;
  }

  if(remainder_cols > 0) {
    block_count += block_rows;
  }

  if(remainder_rows > 0 && remainder_cols > 0) {
    block_count++;
  }

  return block_count;
}

// Function to extract a block of pixels from a vector of YCbCr pixels
void getBlock(std::vector<std::vector<YCbCrPixel>>& ycbcr, int block_num, std::vector<std::vector<YCbCrPixel>>& block) {
  int rows = ycbcr.size();
  int cols = ycbcr[0].size();
  int block_rows = rows / 8;
  int block_cols = cols / 8;
  int remainder_rows = rows % 8;
  int remainder_cols = cols % 8;
  int block_count = block_rows * block_cols;

  if(remainder_rows > 0) {
    block_count += block_cols;
  }

  if(remainder_cols > 0) {
    block_count += block_rows;
  }

  if(remainder_rows > 0 && remainder_cols > 0) {
    block_count++;
  }

  if(block_num >= block_count) {
    return;
  }

  block.clear();
  block.resize(8, std::vector<YCbCrPixel>(8));
  int row = (block_num / block_cols) * 8;
  int col = (block_num % block_cols) * 8;
  for(int i=0; i<8; i++) {
    for(int j=0; j<8; j++) {
      block[i][j] = ycbcr[row+i][col+j];
    }
  }
}

// Function to generate a quantization matrix
void generate_quantization_table(int quality, std::vector<std::vector<int>>& quantization_table) {
  quantization_table.clear();
  quantization_table.resize(8, std::vector<int>(8));
  for(int i=0; i<8; i++) {
    for(int j=0; j<8; j++) {
      quantization_table[i][j] = 1 + (i+j) * quality;
    }
  }
}
