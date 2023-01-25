#ifndef JPEG_SEGMENTS
#define JPEG_SEGMENTS
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
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

enum ThumbnailType {
  JPEG = 0x10,
  PALLETIZED = 0x11,
  RGB = 0x13
};

struct APP0 {
  unsigned char identifier[5];
  unsigned char version[2];
  unsigned char units;
  unsigned char x_density[2];
  unsigned char y_density[2];
  unsigned char x_thumbnail;
  unsigned char y_thumbnail;

  APP0& operator=(unsigned char * data) {
    memcpy(this, data, sizeof(APP0));
    return *this;
  }
};
typedef struct APP0 APP0;

struct SOF0 {
  unsigned char width[2];
  unsigned char height[2];
  unsigned char precision;
  struct Component {
    unsigned char identifier;
    unsigned char sampling_factor;
    unsigned char quantization_table;
  } components[3];

  SOF0& operator=(unsigned char * data) {
    memcpy(this, data, sizeof(SOF0));
    return *this;
  }
};
typedef struct SOF0 SOF0;

struct SOF2 {
  unsigned char width[2];
  unsigned char height[2];
  unsigned char precision;
  struct Component {
    unsigned char identifier;
    unsigned char sampling_factor;
    unsigned char quantization_table;
  } components[3];

  SOF2& operator=(unsigned char * data) {
    memcpy(this, data, sizeof(SOF2));
    return *this;
  }
};
typedef struct SOF2 SOF2;

struct DQT {
  unsigned char precision;
  unsigned char identifier;
  unsigned char table[64];

  struct DQT& operator=(unsigned char * data) {
    precision = data[0];
    identifier = data[1];
    for (int i = 0; i < 64; i++) {
      table[i] = data[i + 2];
    }
    return *this;
  }
};
typedef struct DQT DQT;

struct DHT {
  unsigned char class_id;
  unsigned char identifier;
  unsigned char codes[16];
  unsigned char values[256];

  struct DHT& operator=(unsigned char * data) {
    memcpy(this, data, sizeof(DHT));
    return *this;
  }
};
typedef struct DHT DHT;

struct DRI {
  unsigned char restart_interval[2];

  struct DRI& operator=(unsigned char * data) {
    memcpy(this, data, sizeof(DRI));
    return *this;
  }
};
typedef struct DRI DRI;

struct COM {
  unsigned char comment[256];

  struct COM& operator=(unsigned char * data) {
    memcpy(this, data, sizeof(COM));
    return *this;
  }
};
typedef struct COM COM;

struct SOS {
  unsigned char number_of_components;
  struct Component {
    unsigned char identifier;
    unsigned char huffman_table;
  } components[3];
  unsigned char start_of_spectral_selection;
  unsigned char end_of_spectral_selection;
  unsigned char successive_approximation;

  struct SOS& operator=(unsigned char * data) {
    memcpy(this, data, sizeof(SOS));
    return *this;
  }
};
typedef struct SOS SOS;

#endif
