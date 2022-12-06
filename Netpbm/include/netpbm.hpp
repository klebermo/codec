#ifndef LIB_NETPBM_H
#define LIB_NETPBM_H

#include <string>

class Netpbm {
public:
  virtual void read_file(std::string file_name) = 0;
  virtual void write_file(std::string file_name) = 0;

  int getHeight();
  int getWidth();  
  float * toArray();
};

class Bitmap : public Netpbm {
public:
  Bitmap(std::string file_name);

  void read_file(std::string file_name);
  void write_file(std::string file_name);
};

class Graymap : public Netpbm {
public:
  Graymap(std::string file_name);

  void read_file(std::string file_name);
  void write_file(std::string file_name);
};

class Pixmap2 : public Netpbm {
public:
  Pixmap2(std::string file_name);

  void read_file(std::string file_name);
  void write_file(std::string file_name);
};

#endif
