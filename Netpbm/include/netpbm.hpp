#include <string>
#include <vector>

#ifndef PIXEL_H
#define PIXEL_H

struct Pixel {
  float r, g, b;
};
typedef struct Pixel Pixel;

#endif

#ifndef LIB_NETPBM_H
#define LIB_NETPBM_H

class Netpbm {
protected:
  int max_value;
  std::vector<std::vector<Pixel>> pixels;
public:
  virtual void read_file(std::string file_name) = 0;
  virtual void write_ascii_file(std::string file_name) = 0;
  virtual void write_binary_file(std::string file_name) = 0;

  int getHeight();
  int getWidth();
  void setPixels(std::vector<std::vector<Pixel>> pixels);
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
  void setMaxValue(int max_value);
};

class Pixmap2 : public Netpbm {
private:
  int max_value;
public:
  void read_file(std::string file_name);
  void write_ascii_file(std::string file_name);
  void write_binary_file(std::string file_name);
  void setMaxValue(int max_value);
};

#endif
