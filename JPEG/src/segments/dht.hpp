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
  ~DHT() {}
  void setData(unsigned char * data, int size) {
    this->class_id = data[0];

    this->identifier = data[1];

    for (int i = 0; i < 16; i++) {
      this->codes[i] = data[2 + i];
    }

    for (int i = 0; i < 256; i++) {
      this->values[i] = data[18 + i];
    }
  }
};

#endif
