#ifndef JPEG_H
#define JPEG_H

#include "matrix.hpp"
#include "huffman.hpp"

#include <string>

class JPEG {
protected:
  Matrix<Pixel> pixels;
public:
  JPEG();
  JPEG(int height, int width);
  JPEG(Matrix<Pixel> pixels);

  void read(std::string filename);
  void write(std::string filename);

  int getWidth();
  int getHeight();

  std::vector<float> toArray();
};

#endif
