#ifndef DQT_H
#define DQT_H

#include "../segment.hpp"

class DQT : public Segment {
private:
  unsigned char precision;
  unsigned char identifier;
  unsigned char table[64];
public:
  DQT() : Segment({0xFF, 0xDB}, {0x00, 0x00}) {}
  ~DQT() {}
  void setData(unsigned char * data, int size) {
    this->precision = data[0] >> 4;

    this->identifier = data[0] & 0x0F;

    for (int i = 0; i < 64; i++) {
      this->table[i] = data[i + 1];
    }
  }
};

#endif
