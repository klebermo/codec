#ifndef LIB_NETPBM_H
#define LIB_NETPBM_H

#include <string>

class Netpbm {
public:
  virtual void read_file(std::string file_name) = 0;
  virtual void write_ascii_file(std::string file_name) = 0;
  virtual void write_binary_file(std::string file_name) = 0;
  
  int getHeight();
  int getWidth();
  float * toArray();
};

class Bitmap : public Netpbm {
public:
  void read_file(std::string file_name);
  void write_ascii_file(std::string file_name);
  void write_binary_file(std::string file_name);
};

class Graymap : public Netpbm {
public:
  void read_file(std::string file_name);
  void write_ascii_file(std::string file_name);
  void write_binary_file(std::string file_name);
};

class Pixmap2 : public Netpbm {
public:
  void read_file(std::string file_name);
  void write_ascii_file(std::string file_name);
  void write_binary_file(std::string file_name);
};

#endif
