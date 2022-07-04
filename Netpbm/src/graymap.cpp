#include "graymap.h"

Graymap::Graymap(std::string file_name) {
  this->read_file(file_name);
}

Graymap::~Graymap() {
  for (int i = 0; i < this->height; i++)
    delete[] this->pixels[i];
  delete[] this->pixels;
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

  pixels = new int*[height];
  for(int i=0; i<height; i++) pixels[i] = new int[width];

  if(this->magicNumber == "P2") {
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

  if(this->magicNumber == "P5") {
    for(int i=0; i<height; i++) {
      int * row = new int[width];
      for(int j=0; j<width; j++) {
        char c;
        file.read(&c, 1);
        int bit = (int) c;
        row[j] = bit;
      }
      pixels[i] = row;
    }
  }
}

void Graymap::write_file(std::string file_name) {
  std::ofstream file(file_name);
}

float * Graymap::toArray() {
  float * result = new float[width * height * 5];

  int count = 0;
  for(int i=0; i<height; i++) {
    for(int j=0; j<width; j++) {
      float x = (float)j/(float)width, y = (float)i/(float)height;
      result[count++] = -1 + (2 * x);
      result[count++] = 1 - (2 * y);
      result[count++] = (float)this->pixels[i][j] / (float)this->max_value;
      result[count++] = (float)this->pixels[i][j] / (float)this->max_value;
      result[count++] = (float)this->pixels[i][j] / (float)this->max_value;
    }
  }

  return result;
}