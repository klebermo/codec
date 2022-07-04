#include "pixmap.h"

Pixmap2::Pixmap2(std::string file_name) {
  this->read_file(file_name);
}

Pixmap2::~Pixmap2() {
  for (int i = 0; i < this->getHeight(); i++)
    delete[] this->pixels[i];
  delete[] this->pixels;
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

  pixels = new pixel*[height];
  for(int i=0; i<height; i++) pixels[i] = new pixel[width];

  if(this->magicNumber == "P3") {
    int row=0;
    while(getline(file, line_pixels)) {
      std::string number;
      std::stringstream ss(line_pixels);

      int * line = new int[width];
      int column=0;
      while(getline(ss, number, ' '))
        line[column++] = stoi(number);
      for(int i=0; i<column; i+=3) {
        pixels[row][i].r = line[i];
        pixels[row][i].g = line[i+1];
        pixels[row][i].b = line[i+2];
      }
    }
  }

  if(this->magicNumber == "P6") {
    for(int i=0; i<height; i++) {
      int * row = new int[width*3];
      for(int j=0; j<width; j++) {
        for(int k=0; k<3; k++) {
        char c;
        file.read(&c, 1);
        int bit = (int) c;
        row[j] = bit;
        }
      }
      for(int k=0; k<width*3; k++) {
        pixels[i][k].r = row[k];
        pixels[i][k].g = row[k];
        pixels[i][k].b = row[k];
      }
    }
  }
}

void Pixmap2::write_file(std::string file_name) {
  std::ofstream file(file_name);
}

float * Pixmap2::toArray() {
  float * result;

  int count = 0;
  for(int i=0; i<height; i++) {
    for(int j=0; j<width; j++) {
      float x = (float)j/(float)width, y = (float)i/(float)height;
      result[count++] = -1 + (2 * x);
      result[count++] = 1 - (2 * y);
      result[count++] = (float)this->pixels[i][j].r / (float)this->max_value;
      result[count++] = (float)this->pixels[i][j].g / (float)this->max_value;
      result[count++] = (float)this->pixels[i][j].b / (float)this->max_value;
    }
  }

  return result;
}
