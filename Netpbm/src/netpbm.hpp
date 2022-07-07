#ifndef LIB_NETPBM_H
#define LIB_NETPBM_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

struct Pixel {
  int r, g, b;
};
typedef struct Pixel pixel;

class Netpbm {
protected:
  char * magicNumber;
  int width;
  int height;
public:
  int getWidth();
  int getHeight();

  virtual void read_file(std::string file_name) = 0;
  virtual void write_file(std::string file_name) = 0;
  virtual float * toArray() = 0;
};

#endif  // LIB_NETPBM_H
