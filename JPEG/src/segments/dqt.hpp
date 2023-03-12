#ifndef DQT_H
#define DQT_H

#include "../segment.hpp"

class DQT : public Segment {
private:
  unsigned char precision;
  unsigned char identifier;
  unsigned char table[64];
public:
  DQT() : Segment({0xFF, 0xDB}, 70) {}
  
  unsigned char getPrecision() {
    return precision;
  }

  unsigned char getIdentifier() {
    return identifier;
  }

  unsigned char * getTable() {
    return table;
  }

  void setData(unsigned char * data, int data_length) override {
    precision = data[0];
    identifier = data[1];
    for (int i = 0; i < 64; i++) {
      table[i] = data[i + 2];
    }
  }
};

#endif
