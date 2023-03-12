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
  DHT() : Segment({0xFF, 0xC4}, 278) {}

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

  void setData(unsigned char * data, int data_length) override {
    class_id = data[0];
    identifier = data[1];
    for (int i = 0; i < 16; i++) {
      codes[i] = data[i + 2];
    }
    for (int i = 0; i < 256; i++) {
      values[i] = data[i + 18];
    }
  }
};

#endif
