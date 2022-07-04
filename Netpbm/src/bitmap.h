#ifndef BITMAP_H
#define BITMAP_H

#include "netpbm.h"

#include <iostream>

class Bitmap : public Netpbm {
private:
  std::vector<std::vector<int>> pixels;
public:
  Bitmap(std::string file_name);

  void read_file(std::string file_name);
  void write_file(std::string file_name);
  float * toArray();
};

#endif  // BITMAP_H
