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
std::vector<YCbCrPixel> reduce_resolution_chrome_data(std::vector<YCbCrPixel> ycbcr, int factor) {
  std::vector<YCbCrPixel> result;
  for(int i=0; i<ycbcr.size(); i+=factor) {
    result.push_back(ycbcr[i]);
  }
  return result;
}

// Function to increase the resolution of the chroma data
std::vector<YCbCrPixel> increase_resolution_chrome_data(std::vector<YCbCrPixel> ycbcr, int factor) {
  std::vector<YCbCrPixel> result;
  for(int i=0; i<ycbcr.size(); i++) {
    for(int j=0; j<factor; j++) {
      result.push_back(ycbcr[i]);
    }
  }
  return result;
}

// Function to perform the DCT on a vector of YCbCr pixels
std::vector<YCbCrPixel> dct(std::vector<YCbCrPixel> ycbcr) {
  std::vector<YCbCrPixel> result;
  for(int i=0; i<ycbcr.size(); i++) {
    YCbCrPixel p;
    p.y = ycbcr[i].y;
    p.cb = ycbcr[i].cb;
    p.cr = ycbcr[i].cr;
    result.push_back(p);
  }
  return result;
}

// Function to perform the inverse DCT on a vector of YCbCr pixels
std::vector<YCbCrPixel> idct(std::vector<YCbCrPixel> ycbcr) {
  std::vector<YCbCrPixel> result;
  for(int i=0; i<ycbcr.size(); i++) {
    YCbCrPixel p;
    p.y = ycbcr[i].y;
    p.cb = ycbcr[i].cb;
    p.cr = ycbcr[i].cr;
    result.push_back(p);
  }
  return result;
}

// Function to perform the quantization on a vector of YCbCr pixels
std::vector<YCbCrPixel> quantize(std::vector<YCbCrPixel> ycbcr, int factor) {
  std::vector<YCbCrPixel> result;
  for(int i=0; i<ycbcr.size(); i++) {
    YCbCrPixel p;
    p.y = ycbcr[i].y / factor;
    p.cb = ycbcr[i].cb / factor;
    p.cr = ycbcr[i].cr / factor;
    result.push_back(p);
  }
  return result;
}

// Function to perform the dequantization on a vector of YCbCr pixels
std::vector<YCbCrPixel> dequantize(std::vector<YCbCrPixel> ycbcr, int factor) {
  std::vector<YCbCrPixel> result;
  for(int i=0; i<ycbcr.size(); i++) {
    YCbCrPixel p;
    p.y = ycbcr[i].y * factor;
    p.cb = ycbcr[i].cb * factor;
    p.cr = ycbcr[i].cr * factor;
    result.push_back(p);
  }
  return result;
}
