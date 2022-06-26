#include "bitmap.h"

#include <iostream>

Bitmap::Bitmap(std::string file_name) {
  read_file(file_name);
}

void Bitmap::read_file(std::string file_name) {
  std::cout << "read_file" << std::endl;
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

  if(this->magicNumber == "P1") {
    //
  }

  if(this->magicNumber == "P4") {
    //
  }
}

void Bitmap::write_file(std::string file_name) {
  std::ofstream file(file_name);
}

std::vector<float> Bitmap::toArray() {
  std::vector<float> result;

  for(int i=0; i<height; i++) {
    for(int j=0; j<width; j++) {
      float x = (float)j/(float)width, y = (float)i/(float)height;
      result.push_back(-1 + (2 * x));
      result.push_back(1 - (2 * y));
      result.push_back(pixels[i][j]);
      result.push_back(pixels[i][j]);
      result.push_back(pixels[i][j]);
    }
  }

  return result;
}
