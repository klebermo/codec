#include "pixmap.h"

#include <fstream>
using namespace std;

#include <sstream>
using namespace std;

#include <vector>
using namespace std;

Pixmap2::Pixmap2(char * file_name) {
  this->read_file(file_name);
}

Pixmap2::~Pixmap2() {
  delete pixels;
}

void Pixmap2::read_file(const char * file_name) {
  fstream file;
  file.open(file_name);

  if (file.is_open()) {
    string line_one, line_two, line_three, line_pixels;

    while(getline(file, line_one)) {
      if(line_one.at(0) != '#') {
        if(line_one == "P3")
          this->magicNumber = P3;
        else
          this->magicNumber = P6;
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

    if(this->magicNumber == P3) {
      this->pixels = new Matrix<struct Pixel>(this->width, this->height);

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
          struct Pixel pixel;
          pixel.r = p[count++];
          pixel.g = p[count++];
          pixel.b = p[count++];
          this->pixels->set(i, j, pixel);
        }
      }
    }

    if(this->magicNumber == P6) {
      this->pixels = new Matrix<struct Pixel>(this->width, this->height);

      vector<int> p;
      int size = 3 * width * height;
      for(int i=0; i<size; i++) {
        char byte[1];
        file.read(byte, 1);
        unsigned char c = (unsigned char)byte[0];
        p.push_back( (int)c );
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
  }

  file.close();
}

void Pixmap2::write_file(const char * file_name) {
  fstream file;
  file.open(file_name, ios::out);
  if (file.is_open()) {
    if(magicNumber == P3)
      file << "P3" << endl;
    else
      file << "P6" << endl;
    file << width << " " << height << endl;
    file << max_value << endl;

    if(this->magicNumber == P3) {
      for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
          file << pixels->get(i, j).r << " ";
          file << pixels->get(i, j).g << " ";
          file << pixels->get(i, j).b << " ";
        }
        file << endl;
      }
    }

    if(this->magicNumber == P6) {
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

float * Pixmap2::toArray() {
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
