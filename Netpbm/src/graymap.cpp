#include "graymap.h"

#include <fstream>
using namespace std;

#include <sstream>
using namespace std;

#include <vector>
using namespace std;

Graymap::Graymap() {
  //
}

Graymap::~Graymap() {
  delete pixels;
}

void Graymap::read_file(const char * file_name) {
  fstream file;
  file.open(file_name);

  if (file.is_open()) {
    string line_one, line_two, line_three, line_pixels;

    if (getline(file, line_one))
      this->magicNumber = new string(line_one);

    if (getline(file, line_two)) {
      string width, height;
      stringstream ss(line_two);

      if(getline(ss, width, ' '))
        this->width = stoi(width);

      if(getline(ss, height, ' '))
        this->height = stoi(height);
    }

    if(getline(file, line_three))
      this->max_value = stoi(line_three);

    if(*this->magicNumber == "P2") {
      this->pixels= new Matrix<int>(this->width, this->height);

      vector<int> p;
      while(getline(file, line_pixels)) {
        string number;
        stringstream ss(line_pixels);
        while(getline(ss, number, ' ')) {
          int data = stoi(number);
          p.push_back(data);
        }
      }
      int count = 0;
      for(int i=0; i<this->height; i++) {
        for(int j=0; j<this->width; j++) {
          int data = p[count++];
          this->pixels->set(i, j, data);
        }
      }
    }

    if(*this->magicNumber == "P5") {
      this->pixels= new Matrix<int>(this->width, this->height);

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

void Graymap::write_file(const char * file_name) {
  fstream file;
  file.open(file_name, ios::out);
  if (file.is_open()) {
    file << *magicNumber << endl;
    file << width << " " << height << endl;
    file << max_value << endl;

    if(*this->magicNumber == "P2") {
      for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
          file << pixels->get(i, j) << " ";
        }
        file << endl;
      }
    }

    if(*this->magicNumber == "P5") {
      for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
          int data = pixels->get(i, j);
          unsigned char c = 0x0;
          file << data;
        }
        file << endl;
      }
    }
  }
}

float * Graymap::toArray() {
  int size = 5 * (this->width * this->height);
  float * result = new float[size];

  int count = 0;
  for(int i=0; i<this->height; i++) {
    for(int j=0; j<this->width; j++) {
      float x = (float)j/(float)this->width, y = (float)i/(float)this->height;
      result[count++] = -1 + (2 * x);
      result[count++] = 1 - (2 * y);
      result[count++] = (float)this->pixels->get(i, j) / (float)this->max_value;
      result[count++] = (float)this->pixels->get(i, j) / (float)this->max_value;
      result[count++] = (float)this->pixels->get(i, j) / (float)this->max_value;
    }
  }

  return result;
}

int Graymap::getWidth() {
  return this->width;
}

int Graymap::getHeight() {
  return this->height;
}
