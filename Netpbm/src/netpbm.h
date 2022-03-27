#ifndef LIB_NETPBM_H
#define LIB_NETPBM_H

#include <fstream>
using namespace std;

#include <vector>
using namespace std;

#include "matrix.h"

struct Pixel {
  int r, g, b;
};

class Netpbm {
protected:
  string * magicNumber;
  int width;
  int height;
public:
  Netpbm();
  ~Netpbm();

  virtual void dump_data() = 0;
  virtual void read_file(string file_name) = 0;
  virtual void write_file(string file_name) = 0;
  virtual float * toArray() = 0;
};

#endif  // LIB_NETPBM_H
