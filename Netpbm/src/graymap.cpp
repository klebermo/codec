#include "graymap.hpp"

Graymap::Graymap(std::string file_name) {
  this->read_file(file_name);
}

Graymap::~Graymap() {
  //delete pixels;
}

void Graymap::read_file(std::string file_name) {
  std::ifstream file(file_name);
  std::string line_one, line_two, line_three, line_pixels;

  while(getline(file, line_one)) {
    if(line_one.size() > 0 && line_one.at(0) != '#') {
      setMagicNumber(line_one.at(1));
      break;
    }
  }

  while(getline(file, line_two)) {
    if(line_two.size() > 0 && line_two.at(0) != '#') {
      std::string width, height;
      std::stringstream ss(line_two);

      if(getline(ss, width, ' '))
        setWidth(stoi(width));
      
      if(getline(ss, height, ' '))
        setHeight(stoi(height));
      
      break;
    }
  }

  while(getline(file, line_three)) {
    if(line_three.size() > 0 && line_two.at(0) != '#') {
      this->max_value = stoi(line_three);
      break;
    }
  }

  if(getMagicNumber() == '2') {
    //
  }

  if(getMagicNumber() == '5') {
    //
  }
}

void Graymap::write_file(std::string file_name) {
  if(getMagicNumber() == '2') {
    //
  }

  if(getMagicNumber() == '5') {
    //
  }
}
