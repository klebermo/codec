#ifndef LIB_PNG_H
#define LIB_PNG_H

#include <string>
#include <vector>

#include "../../common/matrix.hpp"
#include "../../common/pixel_rgb.hpp"

class PNG {
private:
  Matrix<rgb> pixels;
public:
  void read(std::string file_name);
  void write(std::string file_name);

  Matrix<rgb> getPixels();
  void setPixels(Matrix<rgb> pixels);

  int getWidth();
  int getHeight();

  bool isAnimation();
  std::vector<float> toArray();
};

#endif  // LIB_PNG_H
