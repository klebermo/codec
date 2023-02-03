#ifndef DHT_H
#define DHT_H

class DHT {
public:
  unsigned char class_id;
  unsigned char identifier;
  unsigned char codes[16];
  unsigned char values[256];
};

#endif
