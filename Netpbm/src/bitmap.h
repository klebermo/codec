#ifndef BITMAP_H
#define BITMAP_H

#include "netpbm.h"

class Bitmap : public Netpbm {
private:
  Matrix<int> * pixels;
public:
  Bitmap(char * file_name);
  ~Bitmap();

  void read_file(const char * file_name);
  void write_file(const char * file_name);
  float * toArray();
};

#endif  // BITMAP_H
