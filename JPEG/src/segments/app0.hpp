#ifndef APP0_H
#define APP0_H

class APP0 {
private:
  unsigned char identifier[5];
  unsigned char version[2];
  unsigned char units;
  unsigned char x_density[2];
  unsigned char y_density[2];
  unsigned char x_thumbnail;
  unsigned char y_thumbnail;
public:
  APP0() {
    identifier[0] = 'J';
    identifier[1] = 'F';
    identifier[2] = 'I';
    identifier[3] = 'F';
    identifier[4] = '\0';
    version[0] = 0x01;
    version[1] = 0x01;
    units = 0x00;
    x_density[0] = 0x00;
    x_density[1] = 0x01;
    y_density[0] = 0x00;
    y_density[1] = 0x01;
    x_thumbnail = 0x00;
    y_thumbnail = 0x00;
  }

  APP0(unsigned char * data) {
    identifier[0] = data[0];
    identifier[1] = data[1];
    identifier[2] = data[2];
    identifier[3] = data[3];
    identifier[4] = '\0';
    version[0] = data[4];
    version[1] = data[5];
    units = data[6];
    x_density[0] = data[7];
    x_density[1] = data[8];
    y_density[0] = data[9];
    y_density[1] = data[10];
    x_thumbnail = data[11];
    y_thumbnail = data[12];
  }

  APP0& operator=(unsigned char * data) {
    identifier[0] = data[0];
    identifier[1] = data[1];
    identifier[2] = data[2];
    identifier[3] = data[3];
    identifier[4] = '\0';
    version[0] = data[4];
    version[1] = data[5];
    units = data[6];
    x_density[0] = data[7];
    x_density[1] = data[8];
    y_density[0] = data[9];
    y_density[1] = data[10];
    x_thumbnail = data[11];
    y_thumbnail = data[12];
    return *this;
  }

  unsigned char * getIdentifier() {
    return identifier;
  }

  unsigned char * getVersion() {
    return version;
  }

  unsigned char getUnits() {
    return units;
  }

  unsigned char * getXdensity() {
    return x_density;
  }

  unsigned char * getYdensity() {
    return y_density;
  }

  unsigned char getXthumbnail() {
    return x_thumbnail;
  }

  unsigned char getYthumbnail() {
    return y_thumbnail;
  }
};

#endif
