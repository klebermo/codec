#include "bitmap.hpp"

Bitmap::Bitmap(std::string file_name) {
  read_file(file_name);
}

void Bitmap::read_file(std::string file_name) {
  std::ifstream file(file_name);
  std::string line_one, line_two, line_pixels;

  while(getline(file, line_one)) {
    if(line_one.size() > 0 && line_one.at(0) != '#') {
      this->magicNumber = line_one.at(1);
      break;
    }
  }

  while(getline(file, line_two)) {
    if(line_two.size() > 0 && line_two.at(0) != '#') {
      std::string width, height;
      std::stringstream ss(line_two);

      if(getline(ss, width, ' '))
        this->width = stoi(width);
      
      if(getline(ss, height, ' '))
        this->height = stoi(height);
      
      break;
    }
  }

  pixels = new Matrix<pixel>(height, width);
  
  if(magicNumber == '1') {
    int row = 0, col = 0;
    while(getline(file, line_pixels)) {
      if(line_pixels.size() > 0 && line_pixels.at(0) != '#') {
        std::string value;
        std::stringstream ss(line_pixels);
        while(getline(ss, value, ' ')) {
          pixel p;
          p.r = p.g = p.b = stoi(value);
          (*pixels)[row][col] = p;
          col++;
          if(col >= width) break;
        }
      }
      col = 0;
      row++;
      if(row >= height) break;
    }
  }

  if(magicNumber == '4') {
    int row = 0, col = 0;
    while(!file.eof()) {
      unsigned char data[1];
      file.read((char*)data, 1);
      for(int i=0; i<8; i++) {
        if(data[0]&(1<<i)) {
          pixel p;
          p.r = p.g = p.b = 1;
          (*pixels)[row][col] = p;
          col++;
          if(col >= width) break;
        } else {
          pixel p;
          p.r = p.g = p.b = 0;
          (*pixels)[row][col] = p;
          col++;
          if(col >= width) break;
        }
      }
      if(col >= width) {
        row++;
        col = 0;
      }
      if(row >= height) break;
    }
  }
}

void Bitmap::write_file(std::string file_name) {
  if(magicNumber == '1') {
    //
  }

  if(magicNumber == '4') {
    //
  }
}
