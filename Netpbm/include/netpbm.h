#ifndef LIB_NETPBM_H
#define LIB_NETPBM_H

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

  void read_file(const char * file_name);
  void write_file(const char * file_name);

  float * toArray();

  int getWidth();
  int getHeight();
};

class Graymap : public Netpbm {
public:
  Graymap();
  ~Graymap();

  void read_file(const char * file_name);
  void write_file(const char * file_name);

  float * toArray();

  int getWidth();
  int getHeight();
};

class Pixmap : public Netpbm {
public:
  Pixmap();
  ~Pixmap();

  void read_file(const char * file_name);
  void write_file(const char * file_name);

  float * toArray();

  int getWidth();
  int getHeight();
};

#endif  // LIB_NETPBM_H
