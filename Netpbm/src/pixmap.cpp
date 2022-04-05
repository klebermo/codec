#include "pixmap.h"

#include <fstream>
using namespace std;

#include <sstream>
using namespace std;

#include <vector>
using namespace std;

#include <iostream>
using namespace std;

Pixmap::Pixmap() {
  //
}

Pixmap::~Pixmap() {
  delete pixels;
}

void Pixmap::read_file(const char * file_name) {
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

    pixels = new Matrix<struct Pixel>(height, width);

    if(*this->magicNumber == "P3") {
      this->pixels= new Matrix<Pixel>(this->width, this->height);

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
          struct Pixel pixel;

          int r = p[count++];
          pixel.r = r;

          int g = p[count++];
          pixel.g = g;

          int b = p[count++];
          pixel.b = b;

          this->pixels->set(i, j, pixel);
        }
      }
    }

    if(*this->magicNumber == "P6") {
      this->pixels= new Matrix<Pixel>(this->width, this->height);

      vector<unsigned char> p;
      while(getline(file, line_pixels)) {
        for(int i=0; i<line_pixels.size(); i++)
          p.push_back((unsigned char)line_pixels.at(i));
      }
      int count = 0;
      for(int i=0; i<this->height; i++) {
        for(int j=0; j<this->width; j++) {
          struct Pixel pixel;

          int r = (int)p.at(count);
          pixel.r = r;

          int g = (int)p.at(count++);
          pixel.g = g;

          int b = (int)p.at(count++);
          pixel.b = b;

          this->pixels->set(i, j, pixel);
        }
      }
    }
  }

  file.close();
}

void Pixmap::write_file(const char * file_name) {
  fstream file;
  file.open(file_name, ios::out);
  if (file.is_open()) {
    file << *magicNumber << endl;
    file << width << " " << height << endl;
    file << max_value << endl;

    if(*this->magicNumber == "P3") {
      for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
          file << pixels->get(i, j).r << " ";
          file << pixels->get(i, j).g << " ";
          file << pixels->get(i, j).b << " ";
        }
        file << endl;
      }
    }

    if(*this->magicNumber == "P6") {
      for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
          int r = pixels->get(i, j).r, g = pixels->get(i, j).g, b = pixels->get(i, j).b;
          unsigned char data_r = 0x0, data_g = 0x0, data_b = 0x0;
          file << data_r << " ";
          file << data_g << " ";
          file << data_b << " ";
        }
        file << endl;
      }
    }
  }
}

float * Pixmap::toArray() {
  int size = 5 * (this->width * this->height);
  float * result = new float[size];

  int count = 0;
  for(int i=0; i<this->height; i++) {
    for(int j=0; j<this->width; j++) {
      float x = (float)j/(float)this->width, y = (float)i/(float)this->height;
      result[count++] = -1 + (2 * x);
      result[count++] = 1 - (2 * y);
      result[count++] = (float)this->pixels->get(i, j).r / (float)this->max_value;
      result[count++] = (float)this->pixels->get(i, j).g / (float)this->max_value;
      result[count++] = (float)this->pixels->get(i, j).b / (float)this->max_value;
    }
  }

  return result;
}

int Pixmap::getWidth() {
  return this->width;
}

int Pixmap::getHeight() {
  return this->height;
}
