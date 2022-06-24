#ifndef LIB_NETPBM_H
#define LIB_NETPBM_H

#include "matrix.h"

#include <string>
using namespace std;

struct Pixel {
  int r, g, b;
};

enum MagicNumber {
  P1, P2, P3, P4, P5, P6
};

class Netpbm {
protected:
  MagicNumber magicNumber;
  int width;
  int height;
public:
  MagicNumber getMagicNumber();
  int getWidth();
  int getHeight();

  virtual void read_file(const char * file_name) = 0;
  virtual void write_file(const char * file_name) = 0;
  virtual float * toArray() = 0;
};

#endif  // LIB_NETPBM_H
