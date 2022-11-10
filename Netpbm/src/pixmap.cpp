#include "pixmap.hpp"

Pixmap2::Pixmap2(std::string file_name) {
  this->read_file(file_name);
}

void Pixmap2::read_file(std::string file_name) {
  std::ifstream file(file_name);
  std::string line_one, line_two, line_three, line_pixels;

  while(getline(file, line_one)) {
    if(line_one.at(0) != '#') {
      magicNumber = line_one.at(1);
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

  while(getline(file, line_three)) {
    if(line_two.at(0) != '#') {
      this->max_value = stoi(line_three);
      break;
    }
  }

  std::cout << "magicNumber: " << this->magicNumber << std::endl;
  std::cout << "height: " << this->height << std::endl;
  std::cout << "width: " << this->width << std::endl;
  std::cout << "max_value: " << this->max_value << std::endl;
  
  if(magicNumber == '3') {
    //
  }

  if(magicNumber == '6') {
    //
  }
}

void Pixmap2::write_file(std::string file_name) {
  if(magicNumber == '3') {
    //
  }

  if(magicNumber == '6') {
    //
  }
}
