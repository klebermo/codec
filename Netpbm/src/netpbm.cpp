#include "netpbm.hpp"

int Netpbm::getHeight() {
  return this->pixels.size();
}

int Netpbm::getWidth() {
  return this->pixels.size() > 0 ? this->pixels[0].size() : 0;
}

std::vector<float> Netpbm::toArray() { 
  std::vector<float> result;
  size_t h = this->pixels.size();
  size_t w = this->pixels.size() > 0 ? this->pixels[0].size() : 0;

  for(size_t i=0; i<h; i++) {
    for(size_t j=0; j<w; j++) {
      float x = (float)j/(float)w, y = (float)i/(float)h;
      result.push_back(-1 + (2 * x));
      result.push_back(1 - (2 * y));
      result.push_back(this->pixels[i][j].r);
      result.push_back(this->pixels[i][j].g);
      result.push_back(this->pixels[i][j].b);
    }
  }

  return result;
}
