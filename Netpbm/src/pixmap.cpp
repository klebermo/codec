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

    while(getline(file, line_three)) {
      if(line_three.at(0) != '#') {
        this->max_value = stoi(line_three);
        break;
      }
    }

    pixels = new Matrix<struct Pixel>(height, width);

    if(*this->magicNumber == "P3") {
      this->pixels= new Matrix<Pixel>(this->width, this->height);

      vector<int> p;
      while(getline(file, line_pixels)) {
        if(line_pixels.size() > 0 && line_pixels.at(0) != '#') {
          string number;
          stringstream ss(line_pixels);
          while(getline(ss, number, ' ')) p.push_back(stoi(number));
        }
      }

      int count = 0;
      for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
          struct Pixel pixel;
          pixel.r = p[count++];
          pixel.g = p[count++];
          pixel.b = p[count++];
          this->pixels->set(i, j, pixel);
        }
      }
    }

    if(*this->magicNumber == "P6") {
      this->pixels= new Matrix<Pixel>(this->width, this->height);

      vector<unsigned char> p;
      while(getline(file, line_pixels)) {
        if(line_pixels.size() > 0 && line_pixels.at(0) != '#') {
          string number;
          stringstream ss(line_pixels);
          while(getline(ss, number)) p.push_back((unsigned char)number.at(0));
        }
      }

      int count = 0;
      for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
          struct Pixel pixel;
          pixel.r = (int)p[count++];
          pixel.g = (int)p[count++];
          pixel.b = (int)p[count++];
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
