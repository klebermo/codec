#include "png.h"

void PNG::read(std::string file_name) {
  //
}

void PNG::write(std::string file_name) {
  //
}

Matrix<rgb> PNG::getPixels() {
  return this->pixels;
}

void PNG::setPixels(Matrix<rgb> pixels) {
  //
}

int PNG::getWidth() {
  return pixels.get_cols();
}

int PNG::getHeight() {
  return pixels.get_rows();
}

bool PNG::isAnimation() {
  return false;
}

std::vector<float> PNG::toArray() {
  std::vector<float> array;
  return array;
}
