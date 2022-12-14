#ifndef LIB_JPEG_H
#define LIB_JPEG_H

#include "matrix.hpp"

#include <string>
#include <vector>

struct Pixel_RGB {
  float r, g, b;
};
typedef struct Pixel_RGB rgb;

struct Pixel_YCbCr {
  float y, cb, cr;
};
typedef struct Pixel_YCbCr ycbcr;

class JPEG {
private:
  Matrix<rgb> pixels;
public:
  JPEG(std::vector<float> pixels);
  JPEG(std::string file_name);
  ~JPEG();

  void read(std::string file_name);
  void write(std::string file_name);
  Matrix<rgb> getPixels();
};

#endif  // LIB_JPEG_H
