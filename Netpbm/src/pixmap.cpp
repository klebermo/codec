#include "pixmap.hpp"

void Pixmap2::read_file(std::string file_name) {
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
    if(line_three.size() > 0 && line_three.at(0) != '#') {
      this->max_value = stoi(line_three);
      break;
    }
  }
  
  if(magicNumber == '3') {
    std::vector<pixel> v;

    while(getline(file, line_pixels)) {
      if(line_pixels.size() > 0 && line_pixels.at(0) != '#') {
        std::stringstream ss(line_pixels);
        std::string value;

        while(getline(ss, value, ' ')) {
          pixel p;
          p.r = stoi(value) / this->max_value;

          getline(ss, value, ' ');
          p.g = stoi(value) / this->max_value;

          getline(ss, value, ' ');
          p.b = stoi(value) / this->max_value;

          v.emplace_back(p);
        }
      }
    }

    size_t h = stoi(height), w = stoi(width);

    int index = 0;
    for(size_t i=0; i<h; i++) {
      std::vector<pixel> row;
      for(size_t j=0; j<w; j++) row.push_back(v[index++]);
      this->pixels.push_back(row);
    }
  }

  if(magicNumber == '6') {
    std::vector<pixel> v;

    char c;
    while(file.get(c)) {
      pixel p;

      unsigned char uc = (unsigned char)c;
      int number = (int)uc;
      p.r = number / this->max_value;

      file.get(c);

      uc = (unsigned char)c;
      number = (int)uc;
      p.g = number / this->max_value;

      file.get(c);

      uc = (unsigned char)c;
      number = (int)uc;
      p.b = number / this->max_value;

      v.push_back(p);
    }

    size_t h = stoi(height), w = stoi(width);

    int counter = 0;
    for(size_t i=0; i<h; i++) {
      std::vector<pixel> row;
      for(size_t j=0; j<w; j++) row.push_back(v[counter++]);
      this->pixels.push_back(row);
    }
  }
}

void Pixmap2::write_ascii_file(std::string file_name) {
  //
}

void Pixmap2::write_binary_file(std::string file_name) {
  //
}
