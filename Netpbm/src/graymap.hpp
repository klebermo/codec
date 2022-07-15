#ifndef GRAYMAP_H
#define GRAYMAP_H

#include "netpbm.hpp"

class Graymap : public Netpbm {
private:
  int max_value;
public:
  Graymap(std::string file_name);
  void read_file(std::string file_name);
  void write_file(std::string file_name);
};

#endif  // GRAYMAP_H
