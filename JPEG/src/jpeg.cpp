#include "jpeg.h"

void JPEG::read(std::string filename) {
  this->jpeg_file->readFile(filename);
}

void JPEG::write(std::string filename) {
  this->jpeg_file->writeFile(filename);
}

std::vector<float> JPEG::toArray() {
  return this->jpeg_file->toArray();
}
