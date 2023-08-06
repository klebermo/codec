#include "avi.hpp"

void AVI::read(std::string filename) {
  //
}

void AVI::write(std::string filename) {
  //
}

int AVI::getFrameCount() {
  return pixels.size();
}

int AVI::getFrameRate() {
  return 30;
}

int AVI::getWidth() {
  return pixels[0].getWidth();
}

int AVI::getHeight() {
  return pixels[0].getHeight();
}
