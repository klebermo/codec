#include "netpbm.hpp"

char Netpbm::getMagicNumber() {
  return magicNumber;
}

int Netpbm::getHeight() {
  return height;
}

int Netpbm::getWidth() {
  return width;
}

Matrix<pixel> * Netpbm::getPixels() {
    return pixels;
}

void Netpbm::setMagicNumber(char value) {
    this->magicNumber = value;
}

void Netpbm::setHeight(int value) {
    this->height = value;
}

void Netpbm::setWidth(int value) {
    this->width = value;
}

void Netpbm::setPixels(Matrix<pixel> * value) {
    this->pixels = value;
}

float * Netpbm::toArray() {
  std::cout << "bitmap::toArray" << std::endl;
  std::cout << "magicNumber: " << magicNumber << std::endl;
  std::cout << "width: " << width << std::endl;
  std::cout << "height: " << height << std::endl;
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
