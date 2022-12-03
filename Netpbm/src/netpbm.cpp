#include "netpbm.hpp"

Netpbm::Netpbm() {}

Netpbm::Netpbm(const Netpbm &other) {
  this->magicNumber = other.magicNumber;
  this->width = other.width;
  this->height = other.height;
}

Netpbm::~Netpbm() {}

char Netpbm::getMagicNumber() {
  return this->magicNumber;
}

int Netpbm::getWidth() {
  return this->width;
}

int Netpbm::getHeight() {
  return this->height;
}

float * Netpbm::toArray() {
  std::cout << "magicNumber: " << magicNumber << std::endl;
  std::cout << "height: " << width << std::endl;
  std::cout << "width: " << width << std::endl;
  float * result = new float[width * height * 5];

  int count = 0;
  for(int i=0; i<height; i++) {
    for(int j=0; j<width; j++) {
      float x = j/width, y=i/height;
      result[count++] = -1 + (2 * x);
      result[count++] = 1 - (2 * y);
      result[count++] = (*pixels)[i][j].r;
      result[count++] = (*pixels)[i][j].g;
      result[count++] = (*pixels)[i][j].b;
    }
  }

  return result;
}
