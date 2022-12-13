#ifndef BITMAP_H
#define BITMAP_H

#include "netpbm.hpp"

class Bitmap : public Netpbm {
public:
  void read_file(std::string file_name);
  void write_ascii_file(std::string file_name);
  void write_binary_file(std::string file_name);
};

#endif
