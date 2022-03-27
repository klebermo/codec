#ifndef PIXMAP_H
#define PIXMAP_H

#include "netpbm.h"

class Pixmap : public Netpbm {
private:
  int max_value;
  Matrix<struct Pixel> * pixels;
public:
  Pixmap();
  ~Pixmap();

  void dump_data();
  void read_file(string file_name);
  void write_file(string file_name);

  float * toArray();

  int getWidth();
  int getHeight();
};

#endif  // PIXMAP_H
