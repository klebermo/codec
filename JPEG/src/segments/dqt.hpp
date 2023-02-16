#ifndef DQT_H
#define DQT_H

class DQT {
private:
  unsigned char precision;
  unsigned char identifier;
  unsigned char table[64];
public:
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
