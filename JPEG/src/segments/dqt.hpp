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
  
  unsigned char getPrecision() {
    return precision;
  }

  unsigned char getIdentifier() {
    return identifier;
  }

  unsigned char * getTable() {
    return table;
  }
};

#endif
