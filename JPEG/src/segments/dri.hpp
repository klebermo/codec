#ifndef DRI_H
#define DRI_H

class DRI {
private:
  unsigned char restart_interval[2];
public:
  unsigned char * getRestartInterval() {
    return restart_interval;
  }
};

#endif
