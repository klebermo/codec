#ifndef LIB_NETPBM_H
#define LIB_NETPBM_H

#include "matrix.h"

#include <string>
using namespace std;

struct Pixel {
  int r, g, b;
};

class Netpbm {
protected:
  string * magicNumber;
  int width;
  int height;
public:
  virtual void read_file(const char * file_name) = 0;
  virtual void write_file(const char * file_name) = 0;
  virtual float * toArray() = 0;
};

#endif  // LIB_NETPBM_H
