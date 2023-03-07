#ifndef DRI_H
#define DRI_H

#include "../segment.hpp"

class DRI : public Segment {
private:
  unsigned char restart_interval[2];
public:
  DRI() : Segment({0xFF, 0xDD}, {0x00, 0x00}) {}
  
  unsigned char * getRestartInterval() {
    return restart_interval;
  }
};

#endif
