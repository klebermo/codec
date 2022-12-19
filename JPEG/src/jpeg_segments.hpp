#ifndef JPEG_SEGMENTS
#define JPEG_SEGMENTS

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <cmath>
#include <array>
#include <map>
#include <initializer_list>
#include <queue>

#include "../../common/matrix.hpp"
#include "../../common/pixel.hpp"
#include "../../common/huffman.hpp"

RgbPixel YCbCrToRgb(const YCbCrPixel& ycbcr);
YCbCrPixel RgbToYCbCr(const RgbPixel& rgb);
std::vector<YCbCrPixel> reduceChromaResolution(const std::vector<YCbCrPixel>& image, int n);
std::vector<YCbCrPixel> calculateDCT(const std::vector<YCbCrPixel>& image, int width, int height);
std::vector<YCbCrPixel> quantize(const std::vector<YCbCrPixel>& dct, int width, int height, const std::array<std::array<int, 8>, 8> quantization_matrix);
std::array<std::array<int, 8>, 8> generateQuantizationMatrix(int quality_factor);
std::vector<uint8_t> compressQuantizedImage(const std::vector<YCbCrPixel>& quantized);
std::vector<unsigned char> decompressQuantizedImage(const std::vector<unsigned char>& compressed, int width, int height);
std::array<std::array<float, 8>, 8> reverseDCTBlock(const std::array<std::array<float, 8>, 8>& block);
std::vector<YCbCrPixel> reverseDCT(const std::vector<YCbCrPixel>& ycbcr);
std::vector<YCbCrPixel> reverseChromaResolutionReduction(const std::vector<YCbCrPixel>& ycbcr, int n);

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

struct SOF2 {
  unsigned char marker[2] = {0xFF, 0xC2};
  unsigned char length[2];
  unsigned char precision;
  unsigned char height[2];
  unsigned char width[2];
  unsigned char num_components;
  unsigned char component_id;
  unsigned char sampling_factor;
  unsigned char quantization_table_id;
};
typedef struct SOF2 SOF2;

struct DHT {
  unsigned char marker[2] = {0xFF, 0xC4};
  unsigned char length[2];
  unsigned char table_class;
  unsigned char table_id;
  unsigned char num_codes[16];
  unsigned char values[256];
};
typedef struct DHT DHT;

struct DQT {
  unsigned char marker[2] = {0xFF, 0xDB};
  unsigned char length[2];
  unsigned char precision;
  unsigned char table_id;
  unsigned char table[64];
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
  unsigned char start_of_spectral_selection;
  unsigned char end_of_spectral_selection;
  unsigned char successive_approximation;
};
typedef struct SOS SOS;

struct RST0 {
  unsigned char marker[2] = {0xFF, 0xD0};
};
typedef struct RST0 RST0;

struct RST1 {
  unsigned char marker[2] = {0xFF, 0xD1};
};
typedef struct RST1 RST1;

struct RST2 {
  unsigned char marker[2] = {0xFF, 0xD2};
};
typedef struct RST2 RST2;

struct RST3 {
  unsigned char marker[2] = {0xFF, 0xD3};
};
typedef struct RST3 RST3;

struct RST4 {
  unsigned char marker[2] = {0xFF, 0xD4};
};
typedef struct RST4 RST4;

struct RST5 {
  unsigned char marker[2] = {0xFF, 0xD5};
};
typedef struct RST5 RST5;

struct RST6 {
  unsigned char marker[2] = {0xFF, 0xD6};
};
typedef struct RST6 RST6;

struct RST7 {
  unsigned char marker[2] = {0xFF, 0xD7};
};
typedef struct RST7 RST7;

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
  std::vector<unsigned char> data;
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
