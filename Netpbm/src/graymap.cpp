#include "graymap.h"

#include <fstream>
using namespace std;

Graymap::Graymap() {
  //
}

Graymap::~Graymap() {
  delete pixels;
}

void Graymap::dump_data() {
  cout << *magicNumber << endl;
  cout << width << " " << height << endl;
  cout << max_value << endl;
  for(int i=0; i<height; i++) {
    for(int j=0; j<width; j++) cout << pixels->get(i, j) << " ";
    cout << endl;
  }
}

void Graymap::read_file(const char * file_name) {
  fstream file;
  file.open(file_name);

  if (file.is_open()) {
    string line_one, line_two, line_three, line_pixels;

    do {
      getline(file, line_one);
    } while (line_one.at(0) != '#');

    if (getline(file, line_one))
      this->magicNumber = new string(line_one);

    do {
      getline(file, line_two);
    } while (line_one.at(0) != '#');

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

    pixels = new Matrix<int>(height, width);

    if(*this->magicNumber == "P2") {
      int line = 0;
      while(getline(file, line_pixels)) {
        if(line_pixels.at(0) != '#') {
          string number;
          stringstream ss(line_pixels);
          for(int column=0; column<width; column++)
            if(getline(ss, number, ' ')) pixels->set(line, column, stoi(number));
          line++;
        }
      }
    } else {
      int line = 0;
      while(getline(file, line_pixels)) {
        if(line_pixels.at(0) != '#') {
          int column = 0;
          for(int i=0; i<line_pixels.size(); i++) {
            unsigned char c = line_pixels.at(i);
            pixels->set(line, column++, (int)c);
          }
        }
        line++;
      }
    }
  }

  file.close();
  dump_data();
}

void Graymap::write_file(const char * file_name) {
  fstream file;
  file.open(file_name, ios::out);
  if (file.is_open()) {
    file << *magicNumber << endl;
    file << width << " " << height << endl;
    file << max_value << endl;
    for(int i=0; i<height; i++) {
      for(int j=0; j<width; j++) {
        file << pixels->get(i, j) << " ";
      }
      file << endl;
    }
  }
}

float * Graymap::toArray() {
  int size = 3 * (this->width * this->height);
  float * result = new float[size];

  int count = 0;
  for(int i=0; i<height; i++) {
    for(int j=0; j<width; j++) {
      result[count++] = pixels->get(i, j) / max_value;
      result[count++] = pixels->get(i, j) / max_value;
      result[count++] = pixels->get(i, j) / max_value;
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
