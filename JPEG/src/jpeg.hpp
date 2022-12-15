#ifndef JPEG_H
#define JPEG_H

#include "jpeg_file.hpp"

class JPEG {
private:
  JpegFile * jpeg_file;
public:
  void read(std::string filename);
  void write(std::string filename);

  std::vector<float> toArray();
};

#endif
