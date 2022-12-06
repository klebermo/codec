#include "netpbm.hpp"

int Netpbm::getHeight() { return height; };

int Netpbm::getWidth() { return width; };

std::vector<float> Netpbm::toArray() {
  std::vector<float> result;
  size_t h = pixels.getHeight(), w = pixels.getWidth();

  for(size_t i=0; i<h; i++) {
    for(size_t j=0; j<w; j++) {
      float x = j/w, y=i/h;
      result.push_back(-1 + (2 * x));
      result.push_back(1 - (2 * y));
      result.push_back(pixels[i][j].r);
      result.push_back(pixels[i][j].g);
      result.push_back(pixels[i][j].b);
    }
  }

  return result;
}
