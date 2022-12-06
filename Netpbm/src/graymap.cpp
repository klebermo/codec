#include "graymap.hpp"

void Graymap::read_file(std::string file_name) {
  std::ifstream file(file_name);
  std::string line_one, line_two, line_three, line_pixels;
  char magicNumber;
  std::string width, height;

  while(getline(file, line_one)) {
    if(line_one.size() > 0 && line_one.at(0) != '#') {
      magicNumber = line_one.at(1);
      break;
    }
  }

  while(getline(file, line_two)) {
    if(line_two.size() > 0 && line_two.at(0) != '#') {
      std::stringstream ss(line_two);
      getline(ss, width, ' ');
      getline(ss, height, ' ');
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

void Graymap::write_ascii_file(std::string file_name) {
  //
}

void Graymap::write_binary_file(std::string file_name) {
  //
}
