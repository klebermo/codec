#ifndef DRI_H
#define DRI_H

class DRI {
private:
  unsigned char restart_interval[2];
public:
  DRI() {
    restart_interval[0] = 0x00;
    restart_interval[1] = 0x00;
  }

  DRI(unsigned char * data) {
    restart_interval[0] = data[0];
    restart_interval[1] = data[1];
  }

  DRI& operator=(unsigned char * data) {
    restart_interval[0] = data[0];
    restart_interval[1] = data[1];
    return *this;
  }

  unsigned char * getRestartInterval() {
    return restart_interval;
  }
};

#endif
