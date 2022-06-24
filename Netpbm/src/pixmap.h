#ifndef PIXMAP_H
#define PIXMAP_H

#include "netpbm.h"

class Pixmap2 : public Netpbm {
private:
  int max_value;
  Matrix<struct Pixel> * pixels;
public:
  Pixmap2(char * file_name);
  ~Pixmap2();

  void read_file(const char * file_name);
  void write_file(const char * file_name);
  float * toArray();
};

#endif  // PIXMAP_H
