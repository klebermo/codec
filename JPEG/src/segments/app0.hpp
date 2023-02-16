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
