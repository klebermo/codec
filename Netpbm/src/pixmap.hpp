#ifndef PIXMAP_H
#define PIXMAP_H

#include "netpbm.hpp"

class Pixmap2 : public Netpbm {
private:
  int max_value;
public:
  Pixmap2(std::string file_name);
  //Pixmap2(const Pixmap2 &other);
  ~Pixmap2();
  void read_file(std::string file_name);
  void write_file(std::string file_name);
};

#endif  // PIXMAP_H
