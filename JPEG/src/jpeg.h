#ifndef LIB_JPEG_H
#define LIB_JPEG_H

#include <string>
#include <vector>

#include "../../common/matrix.hpp"
#include "../../common/pixel_rgb.hpp"
#include "../../common/pixel_ycbcr.hpp"

class JPEG {
private:
  Matrix<rgb> pixels;
public:
  void read(std::string file_name);
  void write(std::string file_name);

  Matrix<rgb> getPixels();
  void setPixels(Matrix<rgb> pixels);

  int getWidth();
  int getHeight();

  std::vector<float> toArray();
};

#endif  // LIB_JPEG_H
