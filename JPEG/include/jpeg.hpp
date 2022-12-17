#ifndef JPEG_H
#define JPEG_H

#include <string>
#include <vector>

struct RgbPixel {};
struct YCbCrPixel {};
template<class T> class Matrix {};

class JpegFile {
private:
  Matrix<RgbPixel> pixels;
};

class JPEG {
private:
  JpegFile * jpeg_file;
public:
  void read(std::string filename);
  void write(std::string filename);

  int getWidth();
  int getHeight();

  std::vector<float> toArray();
};

#endif
