#ifndef PIXMAP_H
#define PIXMAP_H

#include "netpbm.h"

class Pixmap2 : public Netpbm {
private:
  int max_value;
  pixel ** pixels;
public:
  Pixmap2(std::string file_name);
  ~Pixmap2();

  void read_file(std::string file_name);
  void write_file(std::string file_name);
  float * toArray();
};

#endif  // PIXMAP_H
