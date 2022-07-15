#include "graymap.hpp"

Graymap::Graymap(std::string file_name) {
  this->read_file(file_name);
}

void Graymap::read_file(std::string file_name) {
  std::ifstream file(file_name);
  std::string line_one, line_two, line_pixels;
  
  while(getline(file, line_one)) {
    if(line_one.at(0) != '#') {
      this->magicNumber = new char[line_one.length() + 1];
      this->magicNumber = line_one.data();
      break;
    }
  }

  while(getline(file, line_two)) {
    std::string width, height;
    std::stringstream ss(line_two);

    if(line_two.at(0) != '#') {
      if(getline(ss, width, ' '))
        this->width = stoi(width);

      if(getline(ss, height, ' '))
        this->height = stoi(height);

      break;
    }
  }

  if(this->magicNumber == "P2") {
    std::cout << "P2" << std::endl;
    while(getline(file, line_pixels)) {
      if(line_pixels.at(0) != '#') {
        std::string data;
        std::stringstream ss(line_pixels);

        std::vector<pixel> row;
        while(getline(ss, data, ' ')) {
          pixel p;
          p.r = p.g = p.b = stoi(data) / max_value;
          row.push_back(p);
        }
        pixels.push_back(row);
      }
    }
  }

  if(this->magicNumber == "P5") {
    std::cout << "P5" << std::endl;
  }
}

void Graymap::write_file(std::string file_name) {
  std::ofstream file(file_name);

  file << magicNumber << std::endl;
  file << width << " " << height << std::endl;
  file << max_value << std::endl;

  if(this->magicNumber == "P2") {
    for(int i=0; i<height; i++) {
      for(int j=0; j<width; j++) {
        file << (int)(pixels[i][j].r * max_value) << " ";
      }
      file << std::endl;
    }
  }

  if(this->magicNumber == "P5") {
    for(int i=0; i<height; i++) {
      for(int j=0; j<width; j++) {
        unsigned char c = (unsigned char)(pixels[i][j].r * max_value);
        file.write((char*)&c, 1);
      }
    }
  }
}
