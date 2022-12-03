#ifndef LIB_NETPBM_H
#define LIB_NETPBM_H

#include <string>

class Netpbm {
public:
  char getMagicNumber();
  int getHeight();
  int getWidth();

  virtual void read_file(std::string file_name) = 0;
  virtual void write_file(std::string file_name) = 0;

  float * toArray();
};

class Bitmap : public Netpbm {
public:
  Bitmap(std::string file_name);
  ~Bitmap();

  void read_file(std::string file_name);
  void write_file(std::string file_name);
};

class Graymap : public Netpbm {
public:
  Graymap(std::string file_name);
  ~Graymap();

  void read_file(std::string file_name);
  void write_file(std::string file_name);
};

class Pixmap2 : public Netpbm {
public:
  Pixmap2(std::string file_name);
  ~Pixmap2();

  void read_file(std::string file_name);
  void write_file(std::string file_name);
};

#endif  // LIB_NETPBM_H
