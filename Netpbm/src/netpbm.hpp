#ifndef NETPBM_H
#define NETPBM_H

#include "matrix.hpp"

struct Pixel {
    float r, g, b;
};
typedef struct Pixel pixel;

class Netpbm {
protected:
  char magicNumber;
  int width;
  int height;
  Matrix<pixel> pixels;
public:
  virtual void read_file(std::string file_name) = 0;
  virtual void write_file(std::string file_name) = 0;

  int getHeight();
  int getWidth();
  std::vector<float> toArray();
};

#endif  // NETPBM_H
