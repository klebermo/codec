#ifndef JPEG_SEGMENTS
#define JPEG_SEGMENTS

#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <iostream>
#include <cmath>
#include <map>
#include <initializer_list>
#include <queue>

#include "../../common/matrix.hpp"
#include "../../common/pixel.hpp"
#include "../../common/huffman.hpp"

RgbPixel YCbCrToRgb(const YCbCrPixel& ycbcr);
YCbCrPixel RgbToYCbCr(const RgbPixel& rgb);

std::vector<YCbCrPixel> reduceChromaResolution(const std::vector<YCbCrPixel>& image, int n);
std::vector<YCbCrPixel> increaseChromaResolution(const std::vector<YCbCrPixel>& image, int n);

std::vector<YCbCrPixel> calculateDCT(const std::vector<YCbCrPixel>& image, int width, int height);
std::vector<YCbCrPixel> reverseDCT(const std::vector<YCbCrPixel>& image, int width, int height);

std::vector<std::vector<int>> generateQuantizationMatrix(int size);
std::vector<YCbCrPixel> quantizeImage(std::vector<YCbCrPixel>& image, int width, int height, std::vector<std::vector<int>> matrix);
std::vector<YCbCrPixel> dequantizeImage(std::vector<YCbCrPixel>& image, int width, int height, std::vector<std::vector<int>> matrix);

std::vector<unsigned char> encodeImage(const std::vector<YCbCrPixel>& data, std::map<unsigned char, std::vector<bool>>& huffman_table);
std::vector<YCbCrPixel> decodeImage(const std::vector<unsigned char>& data, std::map<unsigned char, std::vector<bool>>& huffman_table, int width, int height);

enum jpeg_type {
  JFIF,
  EXIF
};

struct SOI {
  unsigned char marker[2] = {0xFF, 0xD8};
};
typedef struct SOI SOI;

struct SOF0 {
  unsigned char marker[2] = {0xFF, 0xC0};
  unsigned char length[2];
  unsigned char precision;
  unsigned char height[2];
  unsigned char width[2];
  unsigned char num_components;
  unsigned char component_id;
  unsigned char sampling_factor;
  unsigned char quantization_table_id;
};
typedef struct SOF0 SOF0;

struct DHT {
  unsigned char marker[2] = {0xFF, 0xC4};
  unsigned char length[2];
  unsigned char table_class;
  unsigned char table_id;
  std::vector<unsigned char> num_codes;
  std::vector<unsigned char> table;
};
typedef struct DHT DHT;

struct DQT {
  unsigned char marker[2] = {0xFF, 0xDB};
  unsigned char length[2];
  unsigned char precision;
  unsigned char table_id;
  std::vector<unsigned char> table;
};
typedef struct DQT DQT;

struct DRI {
  unsigned char marker[2] = {0xFF, 0xDD};
  unsigned char length[2];
  unsigned char restart_interval[2];
};
typedef struct DRI DRI;

struct SOS {
  unsigned char marker[2] = {0xFF, 0xDA};
  unsigned char length[2];
  unsigned char num_components;
  unsigned char component_id;
  unsigned char huffman_table_id;
};
typedef struct SOS SOS;

struct JFIF_APP0 {
  unsigned char marker[2] = {0xFF, 0xE0};
  unsigned char length[2];
  unsigned char identifier[5] = {'J', 'F', 'I', 'F', 0x00};
  unsigned char version[2] = {0x01, 0x01};
  unsigned char units;
  unsigned char x_density[2];
  unsigned char y_density[2];
  unsigned char x_thumbnail;
  unsigned char y_thumbnail;
  std::vector<unsigned char> thumbnail;
};
typedef struct JFIF_APP0 JFIF_APP0;

struct JFXX_APP0 {
  unsigned char marker[2] = {0xFF, 0xE0};
  unsigned char length[2];
  unsigned char identifier[5] = {'J', 'F', 'X', 'X', 0x00};
  unsigned char extension_code;
  std::vector<unsigned char> thumbnail;
};
typedef struct JFXX_APP0 JFXX_APP0;

struct COM {
  unsigned char marker[2] = {0xFF, 0xFE};
  unsigned char length[2];
  std::vector<unsigned char> data;
};
typedef struct COM COM;

struct EOI {
  unsigned char marker[2] = {0xFF, 0xD9};
};
typedef struct EOI EOI;

#endif
