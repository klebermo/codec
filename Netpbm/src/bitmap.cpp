#include "bitmap.h"

Bitmap::Bitmap(std::string file_name) {
  read_file(file_name);
}

void Bitmap::read_file(std::string file_name) {
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

  if(this->magicNumber == "P1") {
    while(getline(file, line_pixels)) {
      std::string number;
      std::stringstream ss(line_pixels);

      std::vector<int> row;
      while(getline(ss, number, ' '))
        row.push_back(stoi(number));
      pixels.push_back(row);
    }
  }

  if(this->magicNumber == "P4") {
    for(int i=0; i<height; i++) {
      std::vector<int> row;
      for(int j=0; j<width; j++) {
        char c;
        file.read(&c, 1);
        for(int k=0; k<8; k++) {
          int bit = (c >> k) & 1;
          row.push_back(bit);
        }
      }
      pixels.push_back(row);
    }
  }
}

void Bitmap::write_file(std::string file_name) {
  std::ofstream file(file_name);
}

float * Bitmap::toArray() {
  float * result = new float[width * height * 5];

  int count = 0;
  for(int i=0; i<height; i++) {
    std::cout << "i = " << i << " -> ";
    for(int j=0; j<width; j++) {
      std::cout << "j = " << j << " ";
      float x = (float)j/(float)width, y = (float)i/(float)height;
      result[count++] = -1 + (2 * x);
      result[count++] = 1 - (2 * y);
      result[count++] = pixels[i][j];
      result[count++] = pixels[i][j];
      result[count++] = pixels[i][j];
    }
    std::cout << std::endl;
  }

  return result;
}
