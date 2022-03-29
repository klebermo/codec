#include "pixmap.h"

#include <fstream>
using namespace std;

Pixmap::Pixmap() {
  //
}

Pixmap::~Pixmap() {
  delete pixels;
}

void Pixmap::dump_data() {
  cout << *magicNumber << endl;
  cout << width << " " << height << endl;
  cout << max_value << endl;
  for(int i=0; i<height; i++) {
    for(int j=0; j<width; j++) {
      cout << pixels->get(i, j).r << " ";
      cout << pixels->get(i, j).g << " ";
      cout << pixels->get(i, j).b << " ";
    }
    cout << endl;
  }
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

    int line = 0;
    while(getline(file, line_pixels)) {
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

        pixels->set(line, column, pixel);
      }
      line++;
    }
  }

  file.close();
  dump_data();
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
  int size = 3 * (this->width * this->height);
  float * result = new float[size];

  int count = 0;
  for(int i=0; i<height; i++) {
    for(int j=0; j<width; j++) {
      result[count++] = pixels->get(i, j).r / max_value;
      result[count++] = pixels->get(i, j).g / max_value;
      result[count++] = pixels->get(i, j).b / max_value;
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
