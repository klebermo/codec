#include "graymap.hpp"

void Graymap::read_file(std::string file_name) {
  std::ifstream file(file_name);
  std::string line_one, line_two, line_three, line_pixels;

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

  file >> this->max_value;

  while(file.peek() == '\n') file.get();

  if(file.peek() == '#') {
    std::string comment;
    getline(file, comment);
  }

  if(magicNumber.at(1) == '2') {
    std::vector<Pixel> v;

    while(getline(file, line_pixels)) {
      std::stringstream ss(line_pixels);
      int x;
      while(ss >> x) {
        Pixel p;
        p.r = p.g = p.b = (float)x;
        v.push_back(p);
      }
    }

    int index = 0;
    for(int i=0; i<height; i++) {
      std::vector<Pixel> row;
      for(int j=0; j<width; j++) row.push_back(v[index++]);
      this->pixels.push_back(row);
    }
  }

  if(magicNumber.at(1) == '5') {
    std::vector<Pixel> v;

    char c;
    while(file.get(c)) {
      int number = (unsigned char)c - '0';
      Pixel p;
      p.r = p.g = p.b = (float)number;
      v.push_back(p);
    }

    int counter = 0;
    for(int i=0; i<height; i++) {
      std::vector<Pixel> row;
      for(int j=0; j<width; j++) row.push_back(v[counter++]);
      this->pixels.push_back(row);
    }
  }
}

void Graymap::write_ascii_file(std::string file_name) {
  std::ofstream file(file_name);
  file << "P2" << std::endl;
  file << this->getWidth() << " " << this->getHeight() << std::endl;
  file << this->max_value << std::endl;
  for(int i=0; i<this->getHeight(); i++) {
    for(int j=0; j<this->getWidth(); j++) {
      file << (int)this->pixels[i][j].r << " ";
    }
    file << std::endl;
  }
}

void Graymap::write_binary_file(std::string file_name) {
  std::ofstream file(file_name);
  file << "P5" << std::endl;
  file << this->getWidth() << " " << this->getHeight() << std::endl;
  file << this->max_value << std::endl;
  for(int i=0; i<this->getHeight(); i++) {
    for(int j=0; j<this->getWidth(); j++) {
      char c = (char)this->pixels[i][j].r;
      file.write(&c, 1);
    }
  }
}

void Graymap::setMaxValue(int max_value) {
  this->max_value = max_value;
}
