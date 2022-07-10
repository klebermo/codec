#ifndef PIXMAP_H
#define PIXMAP_H

#include "netpbm.hpp"

class Pixmap2 : public Netpbm {
private:
  int max_value;
public:
  Pixmap2(std::string file_name);
  void read_file(std::string file_name);
  void write_file(std::string file_name);
  float * toArray();
};

#endif  // PIXMAP_H
