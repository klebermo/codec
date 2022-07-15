#include "bitmap.hpp"

Bitmap::Bitmap(std::string file_name) {
  read_file(file_name);
}

void Bitmap::read_file(std::string file_name) {
  std::ifstream file(file_name);
  std::string line_one, line_two, line_pixels;
  
  while(getline(file, line_one)) {
    if(line_one.at(0) != '#') {
      magicNumber = line_one;
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

  if(magicNumber == "P1") {
    std::cout << "P1" << std::endl;
    while(getline(file, line_pixels)) {
      if(line_pixels.at(0) != '#') {
        std::string data;
        std::stringstream ss(line_pixels);

        std::vector<pixel> row;
        while(getline(ss, data, ' ')) {
          int number = data.at(0) - '0';
          pixel p;
          p.r = p.g = p.b = number;
          row.push_back(p);
        }
        pixels.push_back(row);
      }
    }
  }

  if(magicNumber == "P4") {
    std::cout << "P4" << std::endl;
    int row = 0, column = 0;
    for(; row < height; row++) {
      std::vector<pixel> line;
      for(; column < width; column++)
        line.push_back(pixel{0, 0, 0});
      pixels.push_back(line);
    }

    unsigned char c;
    row = 0, column = 0;
    while(file.read((char*)&c, sizeof(unsigned char))) {
      for(int k=0; k<8; k++) {
        bool bit = (c & (1 << k));
        
        pixel p;
        if(bit)
          p.r = p.g = p.b = 1;
        else
          p.r = p.g = p.b = 0;
        pixels[row][column] = p;

        if(column < width) column++;
        else {row++; column = 0;}
      }
    }
  }
}

void Bitmap::write_file(std::string file_name) {
  std::ofstream file(file_name);

  file << magicNumber << std::endl;
  file << width << " " << height << std::endl;

  if(magicNumber == "P1") {
    for(int i=0; i<height; i++) {
      for(int j=0; j<width; j++) {
        file << (int)pixels[i][j].r << " ";
      }
      file << std::endl;
    }
  } else {
    for(int i=0; i<height; i++) {
      for(int j=0; j<width; j+=8) {
        unsigned char c = 0x00;
        for(int k=0; k<8; k++) {
          float p = pixels[i][j+k].r;
          if(p == 1)
            c = 0xFF;
          else
            c = 0x00;
        }
        file.write((char*)&c, 1);
      }
    }
  }
}
