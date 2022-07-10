#include "bitmap.hpp"

Bitmap::Bitmap(std::string file_name) {
  read_file(file_name);
}

void Bitmap::read_file(std::string file_name) {
  std::ifstream file(file_name);
  std::string line_one, line_two, line_pixels;
  
  while(getline(file, line_one)) {
    if(line_one.at(0) != '#') {
      this->magicNumber = new char[line_one.length() + 1];
      this->magicNumber = line_one.data();
      break;
    }
  }

  while(getline(file, line_two)) {
    std::string width, height;
    std::stringstream ss(line_two);

    if(line_two.at(0) != '#') {
      if(getline(ss, width, ' '))
        this->width = stoi(width);

      if(getline(ss, height, ' '))
        this->height = stoi(height);

      break;
    }
  }

  if(this->magicNumber == "P1") {
    //
  }

  if(this->magicNumber == "P4") {
    //
  }
}

void Bitmap::write_file(std::string file_name) {
  std::ofstream file(file_name);

  file << magicNumber << std::endl;
  file << width << " " << height << std::endl;

  if(magicNumber == "P1") {
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        file << pixels[i][j].r << " ";
      }
      file << std::endl;
    }
  } else {
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        file << pixels[i][j].r << " ";
      }
      file << std::endl;
    }
  }
}

float * Bitmap::toArray() {
  float * result = new float[width * height * 5];

  int count = 0;
  for(int i=0; i<height; i++) {
    for(int j=0; j<width; j++) {
      float x = (float)j/(float)width, y = (float)i/(float)height;
      result[count++] = -1 + (2 * x);
      result[count++] = 1 - (2 * y);
      result[count++] = pixels[i][j].r;
      result[count++] = pixels[i][j].g;
      result[count++] = pixels[i][j].b;
    }
  }

  return result;
}
