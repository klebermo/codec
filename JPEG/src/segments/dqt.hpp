#ifndef DQT_H
#define DQT_H

class DQT {
private:
  unsigned char precision;
  unsigned char identifier;
  unsigned char table[64];
public:
  DQT() {
    precision = 0x00;
    identifier = 0x00;
    for (int i = 0; i < 64; i++) {
      table[i] = 0x00;
    }
  }

  DQT(unsigned char * data) {
    precision = data[0];
    identifier = data[1];
    for (int i = 0; i < 64; i++) {
      table[i] = data[2 + i];
    }
  }

  DQT& operator=(unsigned char * data) {
    precision = data[0];
    identifier = data[1];
    for (int i = 0; i < 64; i++) {
      table[i] = data[2 + i];
    }
    return *this;
  }

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
