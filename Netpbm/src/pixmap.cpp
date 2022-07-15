#include "pixmap.hpp"

Pixmap2::Pixmap2(std::string file_name) {
  this->read_file(file_name);
}

void Pixmap2::read_file(std::string file_name) {
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

  if(this->magicNumber == "P3") {
    std::cout << "P3" << std::endl;
    while(getline(file, line_pixels)) {
      if(line_pixels.at(0) != '#') {
        std::string data;
        std::stringstream ss(line_pixels);

        std::vector<pixel> row;
        while(getline(ss, data, ' ')) {
          pixel p;
          p.r = stoi(data) / max_value;

          getline(ss, data, ' ');
          p.g = stoi(data) / max_value;

          getline(ss, data, ' ');
          p.b = stoi(data) / max_value;

          row.push_back(p);
        }
        pixels.push_back(row);
      }
    }
  }

  if(this->magicNumber == "P6") {
    std::cout << "P6" << std::endl;
  }
}

void Pixmap2::write_file(std::string file_name) {
  std::ofstream file(file_name);

  file << magicNumber << std::endl;
  file << width << " " << height << std::endl;
  file << max_value << std::endl;

  if(this->magicNumber == "P3") {
    for(int i=0; i<height; i++) {
      for(int j=0; j<width; j++) {
        file << (int)(pixels[i][j].r * max_value) << " " << (int)(pixels[i][j].g * max_value) << " " << (int)(pixels[i][j].b * max_value) << " ";
      }
    }
  }

  if(this->magicNumber == "P6") {
    for(int i=0; i<height; i++) {
      for(int j=0; j<width; j++) {
        unsigned char r = (unsigned char)(pixels[i][j].r * max_value);
        file.write((char*)&r, 1);
        unsigned char g = (unsigned char)(pixels[i][j].g * max_value);
        file.write((char*)&g, 1);
        unsigned char b = (unsigned char)(pixels[i][j].b * max_value);
        file.write((char*)&b, 1);
      }
    }
  }
}
