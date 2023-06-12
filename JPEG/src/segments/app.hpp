#ifndef APP0_H
#define APP0_H

#include "../segment.hpp"

class APP : public Segment {
public:
  APP(std::initializer_list<unsigned char> marker, std::initializer_list<unsigned char> length) : Segment(marker, length) {}
  ~APP() {}
};

class APP0 : public APP {
public:
  APP0() : APP({0xFF, 0xE0}, {0x00, 0x00}) {}
  void setData(unsigned char * data, int size) {
    //
  }
};

class APP1 : public APP {
public:
  APP1() : APP({0xFF, 0xE1}, {0x00, 0x00}) {}
  void setData(unsigned char * data, int size) {
    //
  }
};

class APP2 : public APP {
public:
  APP2() : APP({0xFF, 0xE2}, {0x00, 0x00}) {}
  void setData(unsigned char * data, int size) {
    //
  }
};

class APP3 : public APP {
public:
  APP3() : APP({0xFF, 0xE3}, {0x00, 0x00}) {}
  void setData(unsigned char * data, int size) {
    //
  }
};

class APP4 : public APP {
public:
  APP4() : APP({0xFF, 0xE4}, {0x00, 0x00}) {}
  void setData(unsigned char * data, int size) {
    //
  }
};

class APP5 : public APP {
public:
  APP5() : APP({0xFF, 0xE5}, {0x00, 0x00}) {}
  void setData(unsigned char * data, int size) {
    //
  }
};

class APP6 : public APP {
public:
  APP6() : APP({0xFF, 0xE6}, {0x00, 0x00}) {}
  void setData(unsigned char * data, int size) {
    //
  }
};

class APP7 : public APP {
public:
  APP7() : APP({0xFF, 0xE7}, {0x00, 0x00}) {}
  void setData(unsigned char * data, int size) {
    //
  }
};

class APP8 : public APP {
public:
  APP8() : APP({0xFF, 0xE8}, {0x00, 0x00}) {}
  void setData(unsigned char * data, int size) {
    //
  }
};

class APP9 : public APP {
public:
  APP9() : APP({0xFF, 0xE9}, {0x00, 0x00}) {}
  void setData(unsigned char * data, int size) {
    //
  }
};

class APP10 : public APP {
public:
  APP10() : APP({0xFF, 0xEA}, {0x00, 0x00}) {}
  void setData(unsigned char * data, int size) {
    //
  }
};

class APP11 : public APP {
public:
  APP11() : APP({0xFF, 0xEB}, {0x00, 0x00}) {}
  void setData(unsigned char * data, int size) {
    //
  }
};

class APP12 : public APP {
public:
  APP12() : APP({0xFF, 0xEC}, {0x00, 0x00}) {}
  void setData(unsigned char * data, int size) {
    //
  }
};

class APP13 : public APP {
public:
  APP13() : APP({0xFF, 0xED}, {0x00, 0x00}) {}
  void setData(unsigned char * data, int size) {
    //
  }
};

class APP14 : public APP {
public:
  APP14() : APP({0xFF, 0xEE}, {0x00, 0x00}) {}
  void setData(unsigned char * data, int size) {
    //
  }
};

class APP15 : public APP {
public:
  APP15() : APP({0xFF, 0xEF}, {0x00, 0x00}) {}
  void setData(unsigned char * data, int size) {
    //
  }
};

#endif
