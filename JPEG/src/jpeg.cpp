#include "jpeg.h"

void JPEG::read(std::string file_name) {
  //
}

void JPEG::write(std::string file_name) {
  //
}

Matrix<rgb> JPEG::getPixels() {
  return this->pixels;
}

void JPEG::setPixels(Matrix<rgb> pixels) {
  //
}

int JPEG::getWidth() {
  return pixels.get_cols();
}

int JPEG::getHeight() {
  return pixels.get_rows();
}

std::vector<float> JPEG::toArray() {
  std::vector<float> array;
  return array;
}
