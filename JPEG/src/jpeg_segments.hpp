#ifndef JPEG_SEGMENTS
#define JPEG_SEGMENTS

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <cmath>

#include "../../common/matrix.hpp"
#include "../../common/pixel.hpp"
#include "../../common/huffman.hpp"

RgbPixel YCbCrToRgb(const YCbCrPixel& ycbcr);
YCbCrPixel RgbToYCbCr(const RgbPixel& rgb);

void reduce_resolution_chrome_data(std::vector<std::vector<YCbCrPixel>>& ycbcr, int factor);
void increase_resolution_chrome_data(std::vector<std::vector<YCbCrPixel>>& ycbcr, int factor);

void dct(std::vector<std::vector<YCbCrPixel>>& ycbcr);
void idct(std::vector<std::vector<YCbCrPixel>>& ycbcr);

void quantize(std::vector<std::vector<YCbCrPixel>>& ycbcr, std::vector<std::vector<int>>& quantization_table);
void dequantize(std::vector<std::vector<YCbCrPixel>>& ycbcr, std::vector<std::vector<int>>& quantization_table);

int getBlockCount(std::vector<std::vector<YCbCrPixel>>& ycbcr);
void getBlock(std::vector<std::vector<YCbCrPixel>>& ycbcr, int block_num, std::vector<std::vector<YCbCrPixel>>& block);
void generate_quantization_table(int quality, std::vector<std::vector<int>>& quantization_table);

template<class T>
std::vector<bool> encode(std::vector<T>& raw_data, std::map<T, std::vector<bool>>& huffman_table) {
    std::vector<bool> result;
    return result;
}

template<class T>
std::vector<T> decode(std::vector<bool>& encoded_data, std::map<T, std::vector<bool>>& huffman_table) {
    std::vector<T> result;
    return result;
}

#endif
