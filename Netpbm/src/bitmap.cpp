#include "bitmap.hpp"

void Bitmap::read_file(std::string file_name) {
  std::ifstream file(file_name);
  std::string line_one, line_two, line_pixels;

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

  if(magicNumber == '1') {
    std::vector<pixel> v;

    while(getline(file, line_pixels)) {
      if(line_pixels.size() > 0 && line_pixels.at(0) != '#') {
        std::stringstream ss(line_pixels);
        std::string value;
        while(getline(ss, value, ' ')) {
          pixel p;
          p.r = p.g = p.b = stoi(value);
          v.emplace_back(p);
        }
      }
    }

    size_t h = stoi(height), w = stoi(width);

    int index = 0;
    for(size_t i=0; i<h; i++) {
      std::vector<pixel> row;
      for(size_t j=0; j<w; j++)
        row.push_back(v[index++]);
      this->pixels.push_back(row);
    }
  }

  if(magicNumber == '4') {
    std::vector<pixel> v;

    unsigned char data[1];
    while(file.read((char*)data, 1)) {
      for(int i=0; i<8; i++) {
        pixel p;
        if(data[0]&(1<<i))
          p.r = p.g = p.b = 1;
        else
          p.r = p.g = p.b = 0;
        v.push_back(p);
      }
    }

    int counter = 0;
    for(int i=0; i<stoi(height); i++) {
      std::vector<pixel> row;
      for(int j=0; j<stoi(width); j++) row.push_back(v[counter++]);
      this->pixels.push_back(row);
    }
  }
}

void Bitmap::write_ascii_file(std::string file_name) {
  //
}

void Bitmap::write_binary_file(std::string file_name) {
  //
}
