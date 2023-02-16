#ifndef DHT_H
#define DHT_H

class DHT {
private:
  unsigned char class_id;
  unsigned char identifier;
  unsigned char codes[16];
  unsigned char values[256];
public:
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
