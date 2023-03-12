#ifndef DRI_H
#define DRI_H

#include "../segment.hpp"

class DRI : public Segment {
private:
  unsigned char restart_interval[2];
public:
  DRI() : Segment({0xFF, 0xDD}, 6) {}
  
  unsigned char * getRestartInterval() {
    return restart_interval;
  }

  void setData(unsigned char * data, int data_length) override {
    restart_interval[0] = data[0];
    restart_interval[1] = data[1];
  }
};

#endif
