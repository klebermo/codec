#ifndef LIB_NETPBM_H
#define LIB_NETPBM_H

template<class T> class Matrix {};

class Netpbm {
public:
  string * getMagicNumber();
  int getWidth();
  int getHeight();
  
  virtual void read_file(const char * file_name) = 0;
  virtual void write_file(const char * file_name) = 0;
  virtual float * toArray() = 0;
};

class Bitmap : public Netpbm {
public:
  Bitmap();
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
  Graymap();
  Graymap(char * file_name);
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
  Pixmap(char * file_name);
  ~Pixmap();

  void read_file(const char * file_name);
  void write_file(const char * file_name);

  float * toArray();

  int getWidth();
  int getHeight();
};

#endif  // LIB_NETPBM_H
