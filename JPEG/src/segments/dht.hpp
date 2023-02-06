#ifndef DHT_H
#define DHT_H

class DHT {
private:
  unsigned char class_id;
  unsigned char identifier;
  unsigned char codes[16];
  unsigned char values[256];
public:
  DHT() {
    class_id = 0x00;
    identifier = 0x00;
    for (int i = 0; i < 16; i++) {
      codes[i] = 0x00;
    }
    for (int i = 0; i < 256; i++) {
      values[i] = 0x00;
    }
  }

  DHT(unsigned char * data) {
    class_id = data[0];
    identifier = data[1];
    for (int i = 0; i < 16; i++) {
      codes[i] = data[2 + i];
    }
    for (int i = 0; i < 256; i++) {
      values[i] = data[18 + i];
    }
  }

  DHT& operator=(unsigned char * data) {
    class_id = data[0];
    identifier = data[1];
    for (int i = 0; i < 16; i++) {
      codes[i] = data[2 + i];
    }
    for (int i = 0; i < 256; i++) {
      values[i] = data[18 + i];
    }
    return *this;
  }

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
