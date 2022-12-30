#ifndef JPEG_H
#define JPEG_H

#include <string>
#include <vector>

struct RgbPixel {};
struct YCbCrPixel {};
template<class T> class Matrix {};

class JPEG {
private:
  Matrix<RgbPixel> pixels;
public:
  void read(std::string filename) = 0;
  void write(std::string filename) = 0;

  int getWidth() = 0;
  int getHeight() = 0;

  std::vector<float> toArray();
};

#endif
