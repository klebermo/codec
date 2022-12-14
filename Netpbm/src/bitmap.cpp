#include "bitmap.hpp"

void Bitmap::read_file(std::string file_name) {
  std::ifstream file(file_name);
  std::string line_one, line_two, line_pixels;

  std::string magicNumber;
  int width, height;

  file >> magicNumber;

  while(file.peek() == '\n') file.get();

  if(file.peek() == '#') {
    std::string comment;
    getline(file, comment);
  }

  file >> width;

  while(file.peek() == '\n') file.get();

  if(file.peek() == '#') {
    std::string comment;
    getline(file, comment);
  }

  file >> height;

  while(file.peek() == '\n') file.get();

  if(file.peek() == '#') {
    std::string comment;
    getline(file, comment);
  }

  this->max_value = 1;

  if(magicNumber.at(1) == '1') {
    std::vector<pixel> v;

    while(getline(file, line_pixels)) {
      std::stringstream ss(line_pixels);
      int x;
      while(ss >> x) {
        pixel p;
        p.r = p.g = p.b = x == 1 ? 0 : 1;
        v.emplace_back(p);
      }
    }

    int index = 0;
    for(int i=0; i<height; i++) {
      std::vector<pixel> row;
      for(int j=0; j<width; j++) row.push_back(v[index++]);
      this->pixels.push_back(row);
    }
  }

  if(magicNumber.at(1) == '4') {
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
  std::ofstream file(file_name);
  file << "P1" << std::endl;
  file << this->getWidth() << " " << this->getHeight() << std::endl;
  for(int i=0; i<this->getHeight(); i++) {
    for(int j=0; j<this->getWidth(); j++) file << this->pixels[i][j].r << " ";
    file << std::endl;
  }
}

void Bitmap::write_binary_file(std::string file_name) {
  std::ofstream file(file_name);
  file << "P4" << std::endl;
  file << this->getWidth() << " " << this->getHeight() << std::endl;
  for(int i=0; i<this->getHeight(); i++) {
    for(int j=0; j<this->getWidth(); j++) {
      char c = this->pixels[i][j].r == 1 ? 0x0 : 0x1;
      file.write(&c, 1);
    }
  }
}
