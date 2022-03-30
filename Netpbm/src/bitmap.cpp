#include "bitmap.h"

#include <fstream>
using namespace std;

#include <sstream>
using namespace std;

Bitmap::Bitmap() {
  //
}

Bitmap::~Bitmap() {
  delete pixels;
}

void Bitmap::read_file(const char * file_name) {
  fstream file;
  file.open(file_name);

  if (file.is_open()) {
    string line_one, line_two, line_pixels;

    if (getline(file, line_one)) {
      this->magicNumber = new string(line_one);
    }

    if (getline(file, line_two)) {
      string width, height;
      stringstream ss(line_two);

      if(getline(ss, width, ' '))
        this->width = stoi(width);

      if(getline(ss, height, ' '))
        this->height = stoi(height);
    }

    if(*this->magicNumber == "P1") {
      this->pixels= new Matrix<int>(this->width, this->height);

      string p;
      while(getline(file, line_pixels)) {
        for(int i=0; i<line_pixels.size(); i++)
          if(line_pixels.at(i) != ' ') p = p + line_pixels.at(i);
      }
      int count = 0;
      for(int i=0; i<this->height; i++) {
        for(int j=0; j<this->width; j++) {
          int data = p.at(count++) - '0';
          this->pixels->set(i, j, data);
        }
      }
    } else {
      this->pixels= new Matrix<int>(this->width*8, this->height);

      string p;
      while(getline(file, line_pixels)) {
        for(int i=0; i<line_pixels.size(); i++) {
          if(line_pixels.at(i) != ' ') p = p + line_pixels.at(i);
        }
      }
      int count = 0;
      for(int i=0; i<height; i++) {
        int column = 0;
        for(int j=0; j<width; j++) {
          for(int k=0; k<8; k++) {
            unsigned char c = p.at(count);
            int data = (c >> k) & 1;
            this->pixels->set(i, column++, data);
          }
          count++;
        }
      }
    }
  }

  file.close();
}

void Bitmap::write_file(const char * file_name) {
  fstream file;
  file.open(file_name, ios::out);
  if (file.is_open()) {
    file << *magicNumber << endl;
    file << width << " " << height << endl;
    for(int i=0; i<this->height; i++) {
      for(int j=0; j<this->width; j++)
        file << pixels->get(i, j) << " ";
      file << endl;
    }
  }
}

float * Bitmap::toArray() {
  int size = 5 * (this->width * this->height);
  float * result = new float[size];

  int count = 0;
  for(int i=0; i<this->height; i++) {
    for(int j=0; j<this->width; j++) {
      float x = (float)j/(float)width, y = (float)i/(float)height;
      result[count++] = -1 + (2 * x);
      result[count++] = 1 - (2 * y);
      result[count++] = pixels->get(i, j);
      result[count++] = pixels->get(i, j);
      result[count++] = pixels->get(i, j);
    }
  }

  return result;
}

int Bitmap::getWidth() {
  return this->width;
}

int Bitmap::getHeight() {
  return this->height;
}
