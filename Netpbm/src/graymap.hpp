#ifndef GRAYMAP_H
#define GRAYMAP_H

#include "netpbm.hpp"

class Graymap : public Netpbm {
private:
  int max_value;
public:
  void read_file(std::string file_name);
  void write_ascii_file(std::string file_name);
  void write_binary_file(std::string file_name);
};

#endif
