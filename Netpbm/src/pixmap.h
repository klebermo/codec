#ifndef PIXMAP_H
#define PIXMAP_H

#include "netpbm.h"

class Pixmap : public Netpbm {
private:
  int max_value;
  Matrix<struct Pixel> * pixels;
public:
  Pixmap();
  Pixmap(char * file_name);
  ~Pixmap();

  void read_file(const char * file_name);
  void write_file(const char * file_name);
  float * toArray();

  int getWidth();
  int getHeight();
};

#endif  // PIXMAP_H
