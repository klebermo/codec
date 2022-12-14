#ifndef LIB_PNG_H
#define LIB_PNG_H

#include "matrix.hpp"

#include <string>
#include <vector>

struct Pixel_RGB {
  float r, g, b;
};
typedef struct Pixel_RGB rgb;

class PNG {
private:
  Matrix<rgb> pixels;
public:
  PNG(std::vector<float> pixels);
  PNG(std::string file_name);
  ~PNG();
  void read(std::string file_name);
  void write(std::string file_name);
  Matrix<rgb> getPixels();
};

#endif  // LIB_PNG_H
