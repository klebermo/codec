#ifndef BITMAP_H
#define BITMAP_H

#include "netpbm.h"

class Bitmap : public Netpbm {
private:
  Matrix<int> * pixels;
public:
  Bitmap();
  ~Bitmap();

  void dump_data();
  void read_file(const char * file_name);
  void write_file(const char * file_name);

  float * toArray();

  int getWidth();
  int getHeight();
};

#endif  // BITMAP_H
