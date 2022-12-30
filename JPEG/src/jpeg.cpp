#include "jpeg.hpp"

std::vector<float> JPEG::toArray() {
  std::vector<float> array;
  int h = this->getHeight(), w = this->getWidth();

  for(int i=0; i<h; i++) {
    for(int j=0; j<w; j++) {
      float x = (float)j/(float)w, y = (float)i/(float)h;
      
      array.push_back(-1 + (2 * x));
      array.push_back(1 - (2 * y));

      RgbPixel p;
      p.r = pixels[i][j].r / 255;
      array.push_back(p.r);
      p.g = pixels[i][j].g / 255;
      array.push_back(p.g);
      p.b = pixels[i][j].b / 255;
      array.push_back(p.b);
    }
  }
  
  return array;
}
