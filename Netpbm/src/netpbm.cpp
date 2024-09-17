#include "netpbm.hpp"

int Netpbm::getHeight() {
  return this->pixels.size();
}

int Netpbm::getWidth() {
  return this->pixels.size() > 0 ? this->pixels[0].size() : 0;
}

void Netpbm::setPixels(std::vector<std::vector<Pixel>> pixels) {
  int h = pixels.size(), w = pixels[0].size() > 0 ? pixels[0].size() : 0;

  for(int i=0; i<h; i++) {
    std::vector<Pixel> row;
    for(int j=0; j<w; j++) {
      Pixel p;
      p.r = pixels[i][j].r;
      p.g = pixels[i][j].g;
      p.b = pixels[i][j].b;
      row.push_back(p);
    }
    this->pixels.push_back(row);
  }
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

      Pixel p;
      p.r = this->pixels[i][j].r / this->max_value;
      result.push_back(p.r);
      p.g = this->pixels[i][j].g / this->max_value;
      result.push_back(p.g);
      p.b = this->pixels[i][j].b / this->max_value;
      result.push_back(p.b);
    }
  }

  return result;
}
