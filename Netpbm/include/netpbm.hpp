#ifndef LIB_NETPBM_H
#define LIB_NETPBM_H

#include <string>
#include <vector>

struct Pixel {
    float r, g, b;
};
typedef struct Pixel pixel;

class Netpbm {
protected:
  std::vector<std::vector<pixel>> pixels;
public:
  virtual void read_file(std::string file_name) = 0;
  virtual void write_ascii_file(std::string file_name) = 0;
  virtual void write_binary_file(std::string file_name) = 0;

  int getHeight();
  int getWidth();
  std::vector<float> toArray();
};

class Bitmap : public Netpbm {
public:
  void read_file(std::string file_name);
  void write_ascii_file(std::string file_name);
  void write_binary_file(std::string file_name);
};

class Graymap : public Netpbm {
private:
  int max_value;
public:
  void read_file(std::string file_name);
  void write_ascii_file(std::string file_name);
  void write_binary_file(std::string file_name);
};

class Pixmap2 : public Netpbm {
private:
  int max_value;
public:
  void read_file(std::string file_name);
  void write_ascii_file(std::string file_name);
  void write_binary_file(std::string file_name);
};

#endif
