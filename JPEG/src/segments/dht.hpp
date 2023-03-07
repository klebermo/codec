#ifndef DHT_H
#define DHT_H

#include "../segment.hpp"

class DHT : public Segment {
private:
  unsigned char class_id;
  unsigned char identifier;
  unsigned char codes[16];
  unsigned char values[256];
public:
  DHT() : Segment({0xFF, 0xC4}, {0x00, 0x00}) {}

  unsigned char getClassId() {
    return class_id;
  }

  unsigned char getIdentifier() {
    return identifier;
  }

  unsigned char * getCodes() {
    return codes;
  }

  unsigned char * getValues() {
    return values;
  }
};

#endif
