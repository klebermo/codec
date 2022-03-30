#include "pixmap.h"

#include <fstream>
using namespace std;

#include <sstream>
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
      int line = 0;
      while(getline(file, line_pixels)) {
        if(line_pixels.at(0) != '#') {
          string number;
          stringstream ss(line_pixels);
          for(int column=0; column<width; column++) {
            struct Pixel pixel;

            if(getline(ss, number, ' ')) {
              pixel.r = stoi(number);
            }

            if(getline(ss, number, ' ')) {
              pixel.g = stoi(number);
            }

            if(getline(ss, number, ' ')) {
              pixel.b = stoi(number);
            }

            this->pixels->set(line, column, pixel);
          }
          line++;
        }
      }
    } else {
      //
    }

    if(*this->magicNumber == "P3") {
      this->pixels= new Matrix<Pixel>(this->width, this->height);

      string p;
      while(getline(file, line_pixels)) {
        for(int i=0; i<line_pixels.size(); i++)
          if(line_pixels.at(i) != ' ') p = p + line_pixels.at(i);
      }
      int count = 0;
      for(int i=0; i<this->height; i++) {
        for(int j=0; j<this->width; j++) {
          struct Pixel pixel;

          int data = p.at(count++) - '0';
          pixel.r = data;

          data = p.at(count++) - '0';
          pixel.g = data;

          data = p.at(count++) - '0';
          pixel.b = data;

          this->pixels->set(i, j, pixel);
        }
      }
    } else {
      this->pixels= new Matrix<Pixel>(this->width*8, this->height);

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
          struct Pixel pixel;

          unsigned char r = p.at(count++);
          for(int k=0; k<8; k++) {
            int data = (r >> k) & 1;
            pixel.r = data;
          }

          unsigned char g = p.at(count++);
          for(int k=0; k<8; k++) {
            int data = (g >> k) & 1;
            pixel.g = data;
          }

          unsigned char b = p.at(count++);
          for(int k=0; k<8; k++) {
            int data = (b >> k) & 1;
            pixel.b = data;
          }

          this->pixels->set(i, column++, pixel);
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
    for(int i=0; i<height; i++) {
      for(int j=0; j<width; j++) {
        file << pixels->get(i, j).r << " ";
        file << pixels->get(i, j).g << " ";
        file << pixels->get(i, j).b << " ";
      }
      file << endl;
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
      result[count++] = this->pixels->get(i, j).r / this->max_value;
      result[count++] = this->pixels->get(i, j).g / this->max_value;
      result[count++] = this->pixels->get(i, j).b / this->max_value;
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
