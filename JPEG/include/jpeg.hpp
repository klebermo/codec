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
  virtual void read(std::string filename) = 0;
  virtual void write(std::string filename) = 0;

  virtual int getWidth() = 0;
  virtual int getHeight() = 0;

  std::vector<float> toArray();
};

class Jfif : public JPEG {
public:
  void read(std::string filename);
  void write(std::string filename);

  int getWidth();
  int getHeight();
};

class Exif : public JPEG {
public:
  void read(std::string filename);
  void write(std::string filename);

  int getWidth();
  int getHeight();
};

#endif
