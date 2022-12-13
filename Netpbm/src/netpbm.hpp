#ifndef NETPBM_H
#define NETPBM_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <bitset>
#include <cstring>
#include <cmath>

struct Pixel {
    float r, g, b;
};
typedef struct Pixel pixel;

class Netpbm {
protected:
  std::vector<std::vector<pixel>> pixels;
public:
  virtual void read_file(std::string file_name) = 0;
  virtual void write_ascii_file(std::string file_name) = 0;
  virtual void write_binary_file(std::string file_name) = 0;

  int getHeight();
  int getWidth();
  std::vector<float> toArray();
};

#endif
