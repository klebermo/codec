#ifndef APP_H
#define APP_H

class APP {
  //
};

class APP0 : public APP {
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

class APP1 : public APP {
private:
  unsigned char identifier[6];
  unsigned char version[2];
  unsigned char units;
  unsigned char x_density[2];
  unsigned char y_density[2];
  unsigned char x_thumbnail;
  unsigned char y_thumbnail;
  unsigned char thumbnail_data[3 * 16 * 16];
public:
  APP1() {
    identifier[0] = 'E';
    identifier[1] = 'x';
    identifier[2] = 'i';
    identifier[3] = 'f';
    identifier[4] = '\0';
    version[0] = 0x00;
    version[1] = 0x01;
    units = 0x00;
    x_density[0] = 0x00;
    x_density[1] = 0x01;
    y_density[0] = 0x00;
    y_density[1] = 0x01;
    x_thumbnail = 0x00;
    y_thumbnail = 0x00;
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

  unsigned char * getThumbnailData() {
    return thumbnail_data;
  }
};

class APP2 : public APP {
private:
  unsigned char * data;
public:
  APP2() {
    data = nullptr;
  }

  APP2(int size) {
    data = new unsigned char[size];
  }

  APP2(unsigned char * data) {
    this->data = data;
  }
};

class APP3 : public APP {
private:
  unsigned char * data;
public:
  APP3() {
    data = nullptr;
  }

  APP3(int size) {
    data = new unsigned char[size];
  }

  APP3(unsigned char * data) {
    this->data = data;
  }
};

class APP4 : public APP {
private:
  unsigned char * data;
public:
  APP4() {
    data = nullptr;
  }

  APP4(int size) {
    data = new unsigned char[size];
  }

  APP4(unsigned char * data) {
    this->data = data;
  }
};

class APP5 : public APP {
private:
  unsigned char * data;
public:
  APP5() {
    data = nullptr;
  }

  APP5(int size) {
    data = new unsigned char[size];
  }

  APP5(unsigned char * data) {
    this->data = data;
  }
};

class APP6 : public APP {
private:
  unsigned char * data;
public:
  APP6() {
    data = nullptr;
  }

  APP6(int size) {
    data = new unsigned char[size];
  }

  APP6(unsigned char * data) {
    this->data = data;
  }
};

class APP7 : public APP {
private:
  unsigned char * data;
public:
  APP7() {
    data = nullptr;
  }

  APP7(int size) {
    data = new unsigned char[size];
  }

  APP7(unsigned char * data) {
    this->data = data;
  }
};

class APP8 : public APP {
private:
  unsigned char * data;
public:
  APP8() {
    data = nullptr;
  }

  APP8(int size) {
    data = new unsigned char[size];
  }

  APP8(unsigned char * data) {
    this->data = data;
  }
};

class APP9 : public APP {
private:
  unsigned char * data;
public:
  APP9() {
    data = nullptr;
  }

  APP9(int size) {
    data = new unsigned char[size];
  }

  APP9(unsigned char * data) {
    this->data = data;
  }
};

class APP10 : public APP {
private:
  unsigned char * data;
public:
  APP10() {
    data = nullptr;
  }

  APP10(int size) {
    data = new unsigned char[size];
  }

  APP10(unsigned char * data) {
    this->data = data;
  }
};

class APP11 : public APP {
private:
  unsigned char * data;
public:
  APP11() {
    data = nullptr;
  }

  APP11(int size) {
    data = new unsigned char[size];
  }

  APP11(unsigned char * data) {
    this->data = data;
  }
};

class APP12 : public APP {
private:
  unsigned char * data;
public:
  APP12() {
    data = nullptr;
  }

  APP12(int size) {
    data = new unsigned char[size];
  }

  APP12(unsigned char * data) {
    this->data = data;
  }
};

class APP13 : public APP {
private:
  unsigned char * data;
public:
  APP13() {
    data = nullptr;
  }

  APP13(int size) {
    data = new unsigned char[size];
  }

  APP13(unsigned char * data) {
    this->data = data;
  }
};

class APP14 : public APP {
private:
  unsigned char * data;
public:
  APP14() {
    data = nullptr;
  }

  APP14(int size) {
    data = new unsigned char[size];
  }

  APP14(unsigned char * data) {
    this->data = data;
  }
};

class APP15 : public APP {
private:
  unsigned char * data;
public:
  APP15() {
    data = nullptr;
  }

  APP15(int size) {
    data = new unsigned char[size];
  }

  APP15(unsigned char * data) {
    this->data = data;
  }
};

#endif
