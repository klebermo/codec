#include "graymap.hpp"

void Graymap::read_file(std::string file_name) {
  std::ifstream file(file_name);
  std::string line_one, line_two, line_three, line_pixels;

  char magicNumber;
  int width, height;

  while(getline(file, line_one)) {
    if(line_one.size() > 0 && line_one.at(0) != '#') {
      magicNumber = line_one.at(1);
      break;
    }
  }

  while(getline(file, line_two)) {
    if(line_two.size() > 0 && line_two.at(0) != '#') {
      std::stringstream ss(line_two);
      ss >> width >> height;
      break;
    }
  }

  while(getline(file, line_three)) {
    if(line_three.size() > 0 && line_three.at(0) != '#') {
      this->max_value = stoi(line_three);
      break;
    }
  }

  if(magicNumber == '2') {
    std::vector<pixel> v;

    while(getline(file, line_pixels)) {
      if(line_pixels.size() > 0 && line_pixels.at(0) != '#') {
        std::stringstream ss(line_pixels);
        int x;
        while(ss >> x) {
          pixel p;
          p.r = p.g = p.b = (float)x / (float)this->max_value;
          v.push_back(p);
        }
      }
    }

    int index = 0;
    for(int i=0; i<height; i++) {
      std::vector<pixel> row;
      for(int j=0; j<width; j++) row.push_back(v[index++]);
      this->pixels.push_back(row);
    }
  }

  if(magicNumber == '5') {
    std::vector<pixel> v;

    char c;
    while(file.get(c)) {
      int number = (unsigned char)c - '0';
      pixel p;
      p.r = p.g = p.b = (float)number / (float)this->max_value;
      v.push_back(p);
    }

    int counter = 0;
    for(int i=0; i<height; i++) {
      std::vector<pixel> row;
      for(int j=0; j<width; j++) row.push_back(v[counter++]);
      this->pixels.push_back(row);
    }
  }
}

void Graymap::write_ascii_file(std::string file_name) {
  //
}

void Graymap::write_binary_file(std::string file_name) {
  //
}
