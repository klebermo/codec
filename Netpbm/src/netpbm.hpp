#ifndef LIB_NETPBM_H
#define LIB_NETPBM_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <bitset>

struct Pixel {
  float r, g, b;
};
typedef struct Pixel pixel;

class Netpbm {
protected:
  std::string magicNumber;
  int width;
  int height;
  std::vector<std::vector<pixel>> pixels;
public:
  int getWidth();
  int getHeight();

  virtual void read_file(std::string file_name) = 0;
  virtual void write_file(std::string file_name) = 0;
  virtual float * toArray() = 0;
};

#endif  // LIB_NETPBM_H
