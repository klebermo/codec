#include "pixmap.hpp"

void Pixmap2::read_file(std::string file_name) {
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

  if(magicNumber.at(1) == '3') {
    std::vector<pixel> v;

    while(getline(file, line_pixels)) {
      if(line_pixels.size() > 0 && line_pixels.at(0) != '#') {
        std::stringstream ss(line_pixels);

        int x;
        while(ss >> x) {
          pixel p;
          p.r = (float)x;

          ss >> x;
          p.g = (float)x;

          ss >> x;
          p.b = (float)x;

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

  if(magicNumber.at(1) == '6') {
    std::vector<pixel> v;

    char c;
    while(file.get(c)) {
      pixel p;

      int number = (unsigned char)c - '0';
      p.r = (float)number;

      file.get(c);

      number = (unsigned char)c - '0';
      p.g = (float)number;

      file.get(c);

      number = (unsigned char)c - '0';
      p.b = (float)number;

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

void Pixmap2::write_ascii_file(std::string file_name) {
  std::ofstream file(file_name);
  file << "P3" << std::endl;
  file << this->getWidth() << " " << this->getHeight() << std::endl;
  file << this->max_value << std::endl;
  for(int i=0; i<this->getHeight(); i++) {
    for(int j=0; j<this->getWidth(); j++) {
      file << (int)(this->pixels[i][j].r) << " ";
      file << (int)(this->pixels[i][j].g) << " ";
      file << (int)(this->pixels[i][j].b) << " ";
    }
    file << std::endl;
  }
}

void Pixmap2::write_binary_file(std::string file_name) {
  std::ofstream file(file_name);
  file << "P6" << std::endl;
  file << this->getWidth() << " " << this->getHeight() << std::endl;
  file << this->max_value << std::endl;
  for(int i=0; i<this->getHeight(); i++) {
    for(int j=0; j<this->getWidth(); j++) {
      char r = (char)this->pixels[i][j].r;
      file.write(&r, 1);
      char g = (char)this->pixels[i][j].g;
      file.write(&g, 1);
      char b = (char)this->pixels[i][j].b;
      file.write(&b, 1);
    }
  }
}

void Pixmap2::setMaxValue(int max_value) {
  this->max_value = max_value;
}
