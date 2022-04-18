#include "netpbm.h"

string * Netpbm::getMagicNumber() {
  return this->magicNumber;
}

int Netpbm::getWidth() {
  return this->width;
}

int Netpbm::getHeight() {
  return this->height;
}
