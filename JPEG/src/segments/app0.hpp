#ifndef APP0_H
#define APP0_H

class APP0 {
public:
  unsigned char identifier[5];
  unsigned char version[2];
  unsigned char units;
  unsigned char x_density[2];
  unsigned char y_density[2];
  unsigned char x_thumbnail;
  unsigned char y_thumbnail;
};

#endif
