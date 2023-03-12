#ifndef APP_H
#define APP_H

#include "../segment.hpp"

class APP : public Segment {
public:
  APP(std::initializer_list<unsigned char> marker, int length) : Segment(marker, length) {}
};

class APP0 : public APP {
private:
  unsigned char identifier[5];
  unsigned char version[2];
  unsigned char units;
  unsigned char x_density[2];
  unsigned char y_density[2];
  unsigned char x_thumbnail;
  unsigned char y_thumbnail;
public:
  APP0() : APP({0xFF, 0xE0}, 16) {}

  unsigned char * getIdentifier() {
    return identifier;
  }

  unsigned char * getVersion() {
    return version;
  }

  unsigned char getUnits() {
    return units;
  }

  unsigned char * getXdensity() {
    return x_density;
  }

  unsigned char * getYdensity() {
    return y_density;
  }

  unsigned char getXthumbnail() {
    return x_thumbnail;
  }

  unsigned char getYthumbnail() {
    return y_thumbnail;
  }

  void setData(unsigned char * data, int data_length) override {
      //
  }
};

class APP1 : public APP {
private:
  unsigned char identifier[6];
  unsigned char version[2];
  unsigned char units;
  unsigned char x_density[2];
  unsigned char y_density[2];
  unsigned char x_thumbnail;
  unsigned char y_thumbnail;
public:
  APP1() : APP({0xFF, 0xE1}, 0) {}

  unsigned char * getIdentifier() {
    return identifier;
  }

  unsigned char * getVersion() {
    return version;
  }

  unsigned char getUnits() {
    return units;
  }

  unsigned char * getXdensity() {
    return x_density;
  }

  unsigned char * getYdensity() {
    return y_density;
  }

  unsigned char getXthumbnail() {
    return x_thumbnail;
  }

  unsigned char getYthumbnail() {
    return y_thumbnail;
  }

  void setData(unsigned char * data, int data_length) override {
      //
  }
};

class APP2 : public APP {
public:
  APP2() : APP({0xFF, 0xE2}, 0) {}

  void setData(unsigned char * data, int data_length) override {
      intToUnsignedCharArr(data_length, length);
  }
};

class APP3 : public APP {
public:
  APP3() : APP({0xFF, 0xE3}, 0) {}

  void setData(unsigned char * data, int data_length) override {
      intToUnsignedCharArr(data_length, length);
  }
};

class APP4 : public APP {
public:
  APP4() : APP({0xFF, 0xE4}, 0) {}

  void setData(unsigned char * data, int data_length) override {
      intToUnsignedCharArr(data_length, length);
  }
};

class APP5 : public APP {
public:
  APP5() : APP({0xFF, 0xE5}, 0) {}

  void setData(unsigned char * data, int data_length) override {
      intToUnsignedCharArr(data_length, length);
  }
};

class APP6 : public APP {
public:
  APP6() : APP({0xFF, 0xE6}, 0) {}

  void setData(unsigned char * data, int data_length) override {
      intToUnsignedCharArr(data_length, length);
  }
};

class APP7 : public APP {
public:
  APP7() : APP({0xFF, 0xE7}, 0) {}

  void setData(unsigned char * data, int data_length) override {
      intToUnsignedCharArr(data_length, length);
  }
};

class APP8 : public APP {
public:
  APP8() : APP({0xFF, 0xE8}, 0) {}

  void setData(unsigned char * data, int data_length) override {
      intToUnsignedCharArr(data_length, length);
  }
};

class APP9 : public APP {
public:
  APP9() : APP({0xFF, 0xE9}, 0) {}

  void setData(unsigned char * data, int data_length) override {
      intToUnsignedCharArr(data_length, length);
  }
};

class APP10 : public APP {
public:
  APP10() : APP({0xFF, 0xEA}, 0) {}

  void setData(unsigned char * data, int data_length) override {
      intToUnsignedCharArr(data_length, length);
  }
};

class APP11 : public APP {
public:
  APP11() : APP({0xFF, 0xEB}, 0) {}

  void setData(unsigned char * data, int data_length) override {
      intToUnsignedCharArr(data_length, length);
  }
};

class APP12 : public APP {
public:
  APP12() : APP({0xFF, 0xEC}, 0) {}

  void setData(unsigned char * data, int data_length) override {
      intToUnsignedCharArr(data_length, length);
  }
};

class APP13 : public APP {
public:
  APP13() : APP({0xFF, 0xED}, 0) {}

  void setData(unsigned char * data, int data_length) override {
      intToUnsignedCharArr(data_length, length);
  }
};

class APP14 : public APP {
public:
  APP14() : APP({0xFF, 0xEE}, 0) {}

  void setData(unsigned char * data, int data_length) override {
      intToUnsignedCharArr(data_length, length);
  }
};

class APP15 : public APP {
public:
  APP15() : APP({0xFF, 0xEF}, 0) {}

  void setData(unsigned char * data, int data_length) override {
      intToUnsignedCharArr(data_length, length);
  }
};

#endif
