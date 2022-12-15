#ifndef LIB_PNG_H
#define LIB_PNG_H

#include <string>
#include <vector>

#include "../../common/matrix.hpp"
#include "../../common/pixel.hpp"

struct IHDR {
  unsigned char marker[4] = {0x49, 0x48, 0x44, 0x52};
  unsigned char width[4];
  unsigned char height[4];
  unsigned char bit_depth;
  unsigned char color_type;
  unsigned char compression_method;
  unsigned char filter_method;
  unsigned char interlace_method;
};
typedef struct IHDR IHDR;

struct IDAT {
  unsigned char marker[4] = {0x49, 0x44, 0x41, 0x54};
  unsigned char length[4];
  unsigned char * data;
};
typedef struct IDAT IDAT;

struct IEND {
  unsigned char marker[4] = {0x49, 0x45, 0x4E, 0x44};
};
typedef struct IEND IEND;

class PNG {
private:
  Matrix<rgb> pixels;
public:
  void read(std::string file_name);
  void write(std::string file_name);

  Matrix<rgb> getPixels();
  void setPixels(Matrix<RgbPixel> pixels);

  int getWidth();
  int getHeight();

  bool isAnimation();
  std::vector<float> toArray();
};

#endif  // LIB_PNG_H
