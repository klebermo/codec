#ifndef LIB_NETPBM_H
#define LIB_NETPBM_H

#include <string>
#include <vector>

class Netpbm {
public:
  int getWidth();
  int getHeight();
  
  virtual void read_file(std::string file_name) = 0;
  virtual void write_file(std::string file_name) = 0;
  virtual std::vector<float> toArray() = 0;
};

class Bitmap : public Netpbm {
public:
  Bitmap(std::string file_name);

  void read_file(std::string file_name);
  void write_file(std::string file_name);
  std::vector<float> toArray();
};

class Graymap : public Netpbm {
public:
  Graymap(std::string file_name);

  void read_file(std::string file_name);
  void write_file(std::string file_name);
  std::vector<float> toArray();
};

class Pixmap2 : public Netpbm {
public:
  Pixmap2(std::string file_name);

  void read_file(std::string file_name);
  void write_file(std::string file_name);
  std::vector<float> toArray();
};

#endif  // LIB_NETPBM_H
