#include "graymap.h"

Graymap::Graymap(std::string file_name) {
  this->read_file(file_name);
}

void Graymap::read_file(std::string file_name) {
  //
}

void Graymap::write_file(std::string file_name) {
  //
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
      result[count++] = (float)this->pixels[i][j] / (float)this->max_value;
      result[count++] = (float)this->pixels[i][j] / (float)this->max_value;
      result[count++] = (float)this->pixels[i][j] / (float)this->max_value;
    }
  }

  return result;
}

/*
#include <fstream>
#include <sstream>
#include <vector>

Graymap::Graymap(char * file_name) {
  this->read_file(file_name);
}

Graymap::~Graymap() {
  delete pixels;
}

void Graymap::read_file(const char * file_name) {
  fstream file;
  file.open(file_name);

  if (file.is_open()) {
    string line_one, line_two, line_three, line_pixels;

    while(getline(file, line_one)) {
      if(line_one.at(0) != '#') {
        if(line_one == "P2")
          this->magicNumber = P2;
        else
          this->magicNumber = P5;
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

    if(this->magicNumber == P2) {
      this->pixels = new Matrix<int>(this->width, this->height);

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
          this->pixels->set(i, j, p[count++]);
        }
      }
    }

    if(this->magicNumber == P5) {
      this->pixels = new Matrix<int>(this->width, this->height);

      vector<int> p;
      int size = width * height;
      for(int i=0; i<size; i++) {
        char byte[1];
        file.read(byte, 1);
        unsigned char c = (unsigned char)byte[0];
        p.push_back( (int)c );
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

void Graymap::write_file(const char * file_name) {
  fstream file;
  file.open(file_name, ios::out);
  if (file.is_open()) {
    if(this->magicNumber == P2)
      file << "P2" << endl;
    else
      file <<  "P5" << endl;
    file << width << " " << height << endl;
    file << max_value << endl;

    if(this->magicNumber == P2) {
      for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
          file << pixels->get(i, j) << " ";
        }
        file << endl;
      }
    }

    if(this->magicNumber == P5) {
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
*/
