#ifndef GRAYMAP_H
#define GRAYMAP_H

#include "netpbm.h"

class Graymap : public Netpbm {
private:
  int max_value;
  int ** pixels;
public:
  Graymap(std::string file_name);
  ~Graymap();

  void read_file(std::string file_name);
  void write_file(std::string file_name);
  float * toArray();
};

#endif  // GRAYMAP_H
