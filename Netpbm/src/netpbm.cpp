#include "netpbm.h"

Netpbm::Netpbm() {
  this->magicNumber = NULL;
}

Netpbm::~Netpbm() {
  delete this->magicNumber;
}
