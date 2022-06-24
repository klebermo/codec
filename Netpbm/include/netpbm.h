#ifndef LIB_NETPBM_H
#define LIB_NETPBM_H

#include <string>

template<class T> class Matrix {};

class Netpbm {
public:
  std::string * getMagicNumber();
  int getWidth();
  int getHeight();
  
  virtual void read_file(const char * file_name) = 0;
  virtual void write_file(const char * file_name) = 0;
  virtual float * toArray() = 0;
};

class Bitmap : public Netpbm {
public:
  Bitmap(char * file_name);
  ~Bitmap();

  void read_file(const char * file_name);
  void write_file(const char * file_name);

  float * toArray();

  int getWidth();
  int getHeight();
};

class Graymap : public Netpbm {
public:
  Graymap(char * file_name);
  ~Graymap();

  void read_file(const char * file_name);
  void write_file(const char * file_name);

  float * toArray();

  int getWidth();
  int getHeight();
};

class Pixmap2 : public Netpbm {
public:
  Pixmap2(char * file_name);
  ~Pixmap2();

  void read_file(const char * file_name);
  void write_file(const char * file_name);

  float * toArray();

  int getWidth();
  int getHeight();
};

#endif  // LIB_NETPBM_H
