#include "bitmap.hpp"

void Bitmap::read_file(std::string file_name) {
  std::ifstream file(file_name);
  std::string line_one, line_two, line_pixels;

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

  if(magicNumber == '1') {
    std::vector<pixel> v;

    while(getline(file, line_pixels)) {
      if(line_pixels.size() > 0 && line_pixels.at(0) != '#') {
        std::stringstream ss(line_pixels);
        std::string value;
        while(getline(ss, value, ' ')) {
          pixel p;
          int x = stoi(value);
          if(x == 0)
            p.r = p.g = p.b = 1;
          else
            p.r = p.g = p.b = 0;
          v.emplace_back(p);
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

  if(magicNumber == '4') {
    std::vector<pixel> v;

    char c;
    while(file.get(c)) {
        for(int i=0; i<8; i++) {
            pixel p;
            int x = (c & (1 << (i ^ 7))) != 0;
            if(x == 0)
              p.r = p.g = p.b = 1;
            else
              p.r = p.g = p.b = 0;
            v.push_back(p);
        }
    }

    int counter = 0;
    for(int i=0; i<height; i++) {
        std::vector<pixel> row;
        for(int j=0; j<((width + 7) & -8); j++) row.push_back(v[counter++]);
        pixels.push_back(row);
    }
  }
}

void Bitmap::write_ascii_file(std::string file_name) {
  //
}

void Bitmap::write_binary_file(std::string file_name) {
  //
}
