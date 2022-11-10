#include "bitmap.hpp"

Bitmap::Bitmap(std::string file_name) {
  read_file(file_name);
}

void Bitmap::read_file(std::string file_name) {
  std::ifstream file(file_name);
  std::string line_one, line_two, line_pixels;

  while(getline(file, line_one)) {
    if(line_one.at(0) != '#') {
      this->magicNumber = line_one.at(1);
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

  std::cout << "magicNumber: " << this->magicNumber << std::endl;
  std::cout << "height: " << this->height << std::endl;
  std::cout << "width: " << this->width << std::endl;

  pixels = new Matrix<pixel>(height, width);
  
  if(magicNumber == '1') {
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
          int value;
          file >> value;
          (*pixels)[i][j].r = (*pixels)[i][j].g = (*pixels)[i][j].b = value;
        }
    }
  }

  if(magicNumber == '4') {
    //
  }
}

void Bitmap::write_file(std::string file_name) {
  if(magicNumber == '1') {
    //
  }

  if(magicNumber == '4') {
    //
  }
}
