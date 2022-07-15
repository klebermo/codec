#include "netpbm.hpp"

int Netpbm::getWidth() {
  return this->width;
}

int Netpbm::getHeight() {
  return this->height;
}

float * Netpbm::toArray() {
  float * result = new float[width * height * 5];

  int count = 0;
  for(float i=0; i<height; i++) {
    for(float j=0; j<width; j++) {
      float x = j/width, y=i/height;
      result[count++] = -1 + (2 * x);
      result[count++] = 1 - (2 * y);
      result[count++] = pixels[i][j].r;
      result[count++] = pixels[i][j].g;
      result[count++] = pixels[i][j].b;
    }
  }

  return result;
}
