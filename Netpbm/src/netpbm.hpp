#ifndef NETPBM_H
#define NETPBM_H

#include "matrix.hpp"

struct Pixel {
    float r, g, b;
};
typedef struct Pixel pixel;

class Netpbm {
private:
  char magicNumber;
  int width;
  int height;
  Matrix<pixel> * pixels;
public:
  ~Netpbm();

  char getMagicNumber();
  int getHeight();
  int getWidth();
  Matrix<pixel> * getPixels();

  void setMagicNumber(char value);
  void setHeight(int value);
  void setWidth(int value);
  void setPixels(Matrix<pixel> * value);

  virtual void read_file(std::string file_name) = 0;
  virtual void write_file(std::string file_name) = 0;

  float * toArray();
};

#endif  // NETPBM_H
