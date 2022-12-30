#ifndef JPEG_H
#define JPEG_H

#include "jpeg_segments.hpp"

class JPEG {
protected:
  Matrix<RgbPixel> pixels;
public:
  virtual void read(std::string filename) = 0;
  virtual void write(std::string filename) = 0;

  virtual int getWidth() = 0;
  virtual int getHeight() = 0;

  std::vector<float> toArray();
};

#endif
