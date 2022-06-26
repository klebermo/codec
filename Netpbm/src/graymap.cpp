#include "graymap.h"

Graymap::Graymap(std::string file_name) {
  this->read_file(file_name);
}

void Graymap::read_file(std::string file_name) {
  std::ifstream file(file_name);
  std::string line_one, line_two, line_pixels;
  
  while(getline(file, line_one)) {
    if(line_one.at(0) != '#') {
      this->magicNumber = new char[line_one.length() + 1];
      this->magicNumber = line_one.data();
      break;
    }
  }

  while(getline(file, line_two)) {
    std::string width, height;
    std::stringstream ss(line_two);

    if(line_two.at(0) != '#') {
      if(getline(ss, width, ' '))
        this->width = stoi(width);

      if(getline(ss, height, ' '))
        this->height = stoi(height);

      break;
    }
  }

  if(this->magicNumber == "P2") {
    //
  }

  if(this->magicNumber == "P5") {
    //
  }
}

void Graymap::write_file(std::string file_name) {
  std::ofstream file(file_name);
}

std::vector<float> Graymap::toArray() {
  std::vector<float> result;

  int count = 0;
  for(int i=0; i<height; i++) {
    for(int j=0; j<width; j++) {
      float x = (float)j/(float)width, y = (float)i/(float)height;
      result.push_back(-1 + (2 * x));
      result.push_back(1 - (2 * y));
      result.push_back((float)this->pixels[i][j] / (float)this->max_value);
      result.push_back((float)this->pixels[i][j] / (float)this->max_value);
      result.push_back((float)this->pixels[i][j] / (float)this->max_value);
    }
  }

  return result;
}
