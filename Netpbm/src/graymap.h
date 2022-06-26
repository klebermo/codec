#ifndef GRAYMAP_H
#define GRAYMAP_H

#include "netpbm.h"

class Graymap : public Netpbm {
private:
  int max_value;
  std::vector<std::vector<int>> pixels;
public:
  Graymap(std::string file_name);

  void read_file(std::string file_name);
  void write_file(std::string file_name);
  std::vector<float> toArray();
};

#endif  // GRAYMAP_H
