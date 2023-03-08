#ifndef APP_H
#define APP_H

#include "../segment.hpp"

class APP : public Segment {
public:
  APP(std::initializer_list<unsigned char> marker, std::initializer_list<unsigned char> length) : Segment(marker, length) {}
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
  APP0() : APP({0xFF, 0xE0}, {0x00, 0x00}) {}

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

  void read(std::ifstream &file) override {
      //
  }

  void write (std::ofstream &file) override {
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
  APP1() : APP({0xFF, 0xE1}, {0x00, 0x00}) {}

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

  void read(std::ifstream &file) override {
      //
  }

  void write (std::ofstream &file) override {
      //
  }
};

class APP2 : public APP {
public:
  APP2() : APP({0xFF, 0xE2}, {0x00, 0x00}) {}

  void read(std::ifstream &file) override {
      //
  }

  void write (std::ofstream &file) override {
      //
  }
};

class APP3 : public APP {
public:
  APP3() : APP({0xFF, 0xE3}, {0x00, 0x00}) {}

  void read(std::ifstream &file) override {
      //
  }

  void write (std::ofstream &file) override {
      //
  }
};

class APP4 : public APP {
public:
  APP4() : APP({0xFF, 0xE4}, {0x00, 0x00}) {}

  void read(std::ifstream &file) override {
      //
  }

  void write (std::ofstream &file) override {
      //
  }
};

class APP5 : public APP {
public:
  APP5() : APP({0xFF, 0xE5}, {0x00, 0x00}) {}

  void read(std::ifstream &file) override {
      //
  }

  void write (std::ofstream &file) override {
      //
  }
};

class APP6 : public APP {
public:
  APP6() : APP({0xFF, 0xE6}, {0x00, 0x00}) {}

  void read(std::ifstream &file) override {
      //
  }

  void write (std::ofstream &file) override {
      //
  }
};

class APP7 : public APP {
public:
  APP7() : APP({0xFF, 0xE7}, {0x00, 0x00}) {}

  void read(std::ifstream &file) override {
      //
  }

  void write (std::ofstream &file) override {
      //
  }
};

class APP8 : public APP {
public:
  APP8() : APP({0xFF, 0xE8}, {0x00, 0x00}) {}

  void read(std::ifstream &file) override {
      //
  }

  void write (std::ofstream &file) override {
      //
  }
};

class APP9 : public APP {
public:
  APP9() : APP({0xFF, 0xE9}, {0x00, 0x00}) {}

  void read(std::ifstream &file) override {
      //
  }

  void write (std::ofstream &file) override {
      //
  }
};

class APP10 : public APP {
public:
  APP10() : APP({0xFF, 0xEA}, {0x00, 0x00}) {}

  void read(std::ifstream &file) override {
      //
  }

  void write (std::ofstream &file) override {
      //
  }
};

class APP11 : public APP {
public:
  APP11() : APP({0xFF, 0xEB}, {0x00, 0x00}) {}

  void read(std::ifstream &file) override {
      //
  }

  void write (std::ofstream &file) override {
      //
  }
};

class APP12 : public APP {
public:
  APP12() : APP({0xFF, 0xEC}, {0x00, 0x00}) {}

  void read(std::ifstream &file) override {
      //
  }

  void write (std::ofstream &file) override {
      //
  }
};

class APP13 : public APP {
public:
  APP13() : APP({0xFF, 0xED}, {0x00, 0x00}) {}

  void read(std::ifstream &file) override {
      //
  }

  void write (std::ofstream &file) override {
      //
  }
};

class APP14 : public APP {
public:
  APP14() : APP({0xFF, 0xEE}, {0x00, 0x00}) {}

  void read(std::ifstream &file) override {
      //
  }

  void write (std::ofstream &file) override {
      //
  }
};

class APP15 : public APP {
public:
  APP15() : APP({0xFF, 0xEF}, {0x00, 0x00}) {}

  void read(std::ifstream &file) override {
      //
  }

  void write (std::ofstream &file) override {
      //
  }
};

#endif
