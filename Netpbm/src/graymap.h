#ifndef GRAYMAP_H
#define GRAYMAP_H

#include "netpbm.h"

class Graymap : public Netpbm {
private:
  int max_value;
  Matrix<int> * pixels;
public:
  Graymap();
  ~Graymap();

  void read_file(const char * file_name);
  void write_file(const char * file_name);

  float * toArray();

  int getWidth();
  int getHeight();
};

#endif  // GRAYMAP_H
