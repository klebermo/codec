#ifndef JPEG_H
#define JPEG_H

#include "jfif.hpp"
#include "exif.hpp"

class JPEG {
private:
  JpegFile * jpeg_file;
public:
  void read(std::string filename);
  void write(std::string filename, Matrix<RgbPixel> pixels, jpeg_type type);

  int getWidth();
  int getHeight();

  std::vector<float> toArray();
};

#endif
