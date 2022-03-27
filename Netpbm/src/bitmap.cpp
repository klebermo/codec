#include "bitmap.h"

Bitmap::Bitmap() {
  //
}

Bitmap::~Bitmap() {
  delete pixels;
}

void Bitmap::dump_data() {
  cout << *magicNumber << endl;
  cout << width << " " << height << endl;
  for(int i=0; i<height; i++) {
    for(int j=0; j<width; j++) {
      cout << pixels->get(i, j) << " ";
    }
    cout << endl;
  }
}

void Bitmap::read_file(string file_name) {
  fstream file;
  file.open(file_name.c_str());

  if (file.is_open()) {
    string line_one, line_two, line_pixels;

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

    pixels = new Matrix<int>(height, width);

    int line = 0;
    while(getline(file, line_pixels)) {
      string number;
      stringstream ss(line_pixels);
      for(int column=0; column<width; column++)
        if(getline(ss, number, ' ')) pixels->set(line, column, stoi(number));
      line++;
    }
  }

  file.close();
  dump_data();
}

void Bitmap::write_file(string file_name) {
  fstream file;
  file.open(file_name, ios::out);
  if (file.is_open()) {
    file << *magicNumber << endl;
    file << width << " " << height << endl;
    for(int i=0; i<height; i++) {
      for(int j=0; j<width; j++) {
        file << pixels->get(i, j) << " ";
      }
      file << endl;
    }
  }
}

float * Bitmap::toArray() {
  vector<float> result;

  for(int i=0; i<height; i++) {
    for(int j=0; j<width; j++) {
      result.push_back(pixels->get(i, j) * 1);
      result.push_back(pixels->get(i, j) * 1);
      result.push_back(pixels->get(i, j) * 1);
    }
  }

  return result.data();
}

int Bitmap::getWidth() {
  return this->width;
}

int Bitmap::getHeight() {
  return this->height;
}
