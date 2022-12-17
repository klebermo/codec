#ifndef JPEG_H
#define JPEG_H

#include "jfif.hpp"
#include "exif.hpp"

class JPEG {
private:
  JpegFile * jpeg_file;
public:
  bool read(std::string filename);
  bool write(std::string filename, Matrix<RgbPixel> pixels, jpeg_type type);

  int getWidth();
  int getHeight();

  std::vector<float> toArray();
};

#endif
