#ifndef JPEG_SEGMENTS
#define JPEG_SEGMENTS

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cmath>

#include "../../common/matrix.hpp"
#include "../../common/pixel.hpp"
#include "../../common/huffman.hpp"

RgbPixel YCbCrToRgb(const YCbCrPixel& ycbcr);
YCbCrPixel RgbToYCbCr(const RgbPixel& rgb);

std::vector<YCbCrPixel> reduce_resolution_chrome_data(std::vector<YCbCrPixel> ycbcr, int factor);
std::vector<YCbCrPixel> increase_resolution_chrome_data(std::vector<YCbCrPixel> ycbcr, int factor);

std::vector<YCbCrPixel> dct(std::vector<YCbCrPixel> ycbcr);
std::vector<YCbCrPixel> idct(std::vector<YCbCrPixel> ycbcr);

std::vector<YCbCrPixel> quantize(std::vector<YCbCrPixel> ycbcr, int quality);
std::vector<YCbCrPixel> dequantize(std::vector<YCbCrPixel> ycbcr, int quality);

template<class T>
std::vector<bool> encode(std::vector<T> raw_data) {
    std::vector<bool> result;
    return result;
}

template<class T>
std::vector<T> decode(std::vector<bool> encoded_data) {
    std::vector<T> result;
    return result;
}

#endif
