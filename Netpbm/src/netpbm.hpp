#ifndef LIB_NETPBM_H
#define LIB_NETPBM_H

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
  Matrix<pixel> * pixels;
public:
  Netpbm();
  ~Netpbm();

  int getWidth();
  int getHeight();

  virtual void read_file(char * file_name) = 0;
  virtual void write_file(char * file_name) = 0;
  
  float * toArray();
};

#endif  // LIB_NETPBM_H
