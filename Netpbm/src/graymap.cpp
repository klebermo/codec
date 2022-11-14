#include "graymap.hpp"

Graymap::Graymap(std::string file_name) {
  this->read_file(file_name);
}

void Graymap::read_file(std::string file_name) {
  std::ifstream file(file_name);
  std::string line_one, line_two, line_three, line_pixels;

  while(getline(file, line_one)) {
    if(line_one.size() > 0 && line_one.at(0) != '#') {
      magicNumber = line_one.at(1);
      break;
    }
  }

  while(getline(file, line_two)) {
    if(line_two.size() > 0 && line_two.at(0) != '#') {
      std::string width, height;
      std::stringstream ss(line_two);

      if(getline(ss, width, ' '))
        this->width = stoi(width);
      
      if(getline(ss, height, ' '))
        this->height = stoi(height);
      
      break;
    }
  }

  while(getline(file, line_three)) {
    if(line_three.size() > 0 && line_two.at(0) != '#') {
      this->max_value = stoi(line_three);
      break;
    }
  }

  if(magicNumber == '2') {
    //
  }

  if(magicNumber == '5') {
    //
  }
}

void Graymap::write_file(std::string file_name) {
  if(magicNumber == '2') {
    //
  }

  if(magicNumber == '5') {
    //
  }
}
