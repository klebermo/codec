#include "bitmap.h"

#include <fstream>
using namespace std;

#include <sstream>
using namespace std;

#include <vector>
using namespace std;

Bitmap::Bitmap() {
  //
}

Bitmap::Bitmap(char * file_name) {
  this->read_file(file_name);
}

Bitmap::~Bitmap() {
  delete pixels;
}

void Bitmap::read_file(const char * file_name) {
  fstream file;
  file.open(file_name);

  if (file.is_open()) {
    string line_one, line_two, line_pixels;

    while(getline(file, line_one)) {
      if(line_one.at(0) != '#') {
        this->magicNumber = new string(line_one);
        break;
      }
    }

    while(getline(file, line_two)) {
      string width, height;
      stringstream ss(line_two);

      if(line_two.at(0) != '#') {
        if(getline(ss, width, ' '))
          this->width = stoi(width);

        if(getline(ss, height, ' '))
          this->height = stoi(height);

        break;
      }
    }

    if(*this->magicNumber == "P1") {
      this->pixels = new Matrix<int>(this->width, this->height);

      vector<int> p;
      while(getline(file, line_pixels)) {
        if(line_pixels.size() > 0 && line_pixels.at(0) != '#') {
          string number;
          stringstream ss(line_pixels);
          while(getline(ss, number, ' ')) {
            int data = stoi(number);
            p.push_back(data);
          }
        }
      }

      int count = 0;
      for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
          this->pixels->set(i, j, p[count++]);
        }
      }
    }

    if(*this->magicNumber == "P4") {
      this->pixels = new Matrix<int>(this->width, this->height);

      vector<int> p;
      int size = width * height;
      for(int i=0; i<size; i++) {
        char byte[1];
        file.read(byte, 1);
        unsigned char c = (unsigned char)byte[0];
        for(int x=0; x != 8; x++)
          p.push_back( (c & (1 << x)) != 0 );
      }

      int count = 0;
      for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
          this->pixels->set(i, j, p[count++]);
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
    file << *this->magicNumber << endl;
    file << this->width << " " << this->height << endl;

    if(*this->magicNumber == "P1") {
      for(int i=0; i<this->height; i++) {
        for(int j=0; j<this->width; j++)
          file << pixels->get(i, j) << " ";
        file << endl;
      }
    }

    if(*this->magicNumber == "P4") {
      for(int i=0; i<this->height; i++) {
        for(int j=0; j<this->width; j+=8) {
          int data = pixels->get(i, j);
          unsigned char c = 0x0;
          file << c;
        }
        file << endl;
      }
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
