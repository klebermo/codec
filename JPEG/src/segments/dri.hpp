#ifndef DRI_H
#define DRI_H

#include "../segment.hpp"

class DRI : public Segment {
private:
  unsigned char restart_interval[2];
public:
  DRI() : Segment({0xFF, 0xDD}, {0x00, 0x00}) {}
  ~DRI() {}
  void setData(unsigned char * data, int size) {
    this->restart_interval[0] = data[0];
    this->restart_interval[1] = data[1];
  }
};

#endif
