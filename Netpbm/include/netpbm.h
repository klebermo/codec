#ifndef LIB_NETPBM_H
#define LIB_NETPBM_H

#include <string>
using namespace std;

template<class T> class Matrix {};

class Netpbm {
public:
  Netpbm();
  ~Netpbm();
};

class Bitmap : public Netpbm {
public:
  Bitmap();
  ~Bitmap();

  void dump_data();
  void read_file(string file_name);
  void write_file(string file_name);

  float * toArray();

  int getWidth();
  int getHeight();
};

class Graymap : public Netpbm {
public:
  Graymap();
  ~Graymap();

  void dump_data();
  void read_file(string file_name);
  void write_file(string file_name);

  float * toArray();

  int getWidth();
  int getHeight();
};

class Pixmap : public Netpbm {
public:
  Pixmap();
  ~Pixmap();

  void dump_data();
  void read_file(string file_name);
  void write_file(string file_name);

  float * toArray();

  int getWidth();
  int getHeight();
};

#endif  // LIB_NETPBM_H
