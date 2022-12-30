#ifndef JPEG_SEGMENTS
#define JPEG_SEGMENTS

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

#include "../../common/matrix.hpp"
#include "../../common/pixel.hpp"
#include "../../common/huffman.hpp"

RgbPixel YCbCrToRgb(const YCbCrPixel& ycbcr);
YCbCrPixel RgbToYCbCr(const RgbPixel& rgb);

struct SOI {
  uint16_t marker;
};

struct JFIF_APP0 {
  uint16_t marker;
  uint16_t length;
  uint8_t identifier[5];
  uint16_t version;
  uint8_t units;
  uint16_t x_density;
  uint16_t y_density;
  uint8_t x_thumbnail;
  uint8_t y_thumbnail;
};

struct SOF {
  uint16_t marker;
  uint16_t length;
  uint8_t precision;
  uint16_t height;
  uint16_t width;
  uint8_t num_components;
  uint8_t component_id;
  uint8_t sampling_factor;
  uint8_t quantization_table;
};

struct DQT {
  uint16_t marker;
  uint16_t length;
  uint8_t precision;
  uint8_t table_id;
  std::vector<uint8_t> table;
};

struct DHT {
  uint16_t marker;
  uint16_t length;
  uint8_t table_class;
  uint8_t table_id;
  std::vector<uint8_t> table;
};

struct COM {
  uint16_t marker;
  uint16_t length;
  std::vector<uint8_t> comment;
};

struct SOS {
  uint16_t marker;
  uint16_t length;
  uint8_t num_components;
  uint8_t component_id;
  uint8_t huffman_table;
};

struct EOI {
  uint16_t marker;
};

#endif
