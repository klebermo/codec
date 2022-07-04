#include "bitmap.h"

Bitmap::Bitmap(std::string file_name) {
  read_file(file_name);
}

Bitmap::~Bitmap() {
  for (int i = 0; i < height; i++)
    delete[] pixels[i];
  delete[] pixels;
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

  pixels = new int*[height];
  for(int i=0; i<height; i++) pixels[i] = new int[width];

  if(this->magicNumber == "P1") {
    int row=0;
    while(getline(file, line_pixels)) {
      std::string number;
      std::stringstream ss(line_pixels);

      int * line = new int[width];
      int column=0;
      while(getline(ss, number, ' '))
        line[column++] = stoi(number);
      pixels[row] = line;
    }
  }

  if(this->magicNumber == "P4") {
    for(int i=0; i<height; i++) {
      int * row = new int[width];
      for(int j=0; j<width; j++) {
        char c;
        file.read(&c, 1);
        for(int k=0; k<8; k++) {
          int bit = (c >> k) & 1;
          row[j] = bit;
        }
      }
      pixels[i] = row;
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
    for(int j=0; j<width; j++) {
      float x = (float)j/(float)width, y = (float)i/(float)height;
      result[count++] = -1 + (2 * x);
      result[count++] = 1 - (2 * y);
      result[count++] = pixels[i][j];
      result[count++] = pixels[i][j];
      result[count++] = pixels[i][j];
    }
  }

  return result;
}
