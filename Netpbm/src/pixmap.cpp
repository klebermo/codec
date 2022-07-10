#include "pixmap.hpp"

Pixmap2::Pixmap2(std::string file_name) {
  this->read_file(file_name);
}

void Pixmap2::read_file(std::string file_name) {
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

  if(this->magicNumber == "P3") {
    //
  }

  if(this->magicNumber == "P6") {
    //
  }
}

void Pixmap2::write_file(std::string file_name) {
  std::ofstream file(file_name);

  file << magicNumber << std::endl;
  file << width << " " << height << std::endl;

  if(magicNumber == "P3") {
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        file << pixels[i][j].r << " " << pixels[i][j].g << " " << pixels[i][j].b << std::endl;
      }
    }
  } else {
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        file << pixels[i][j].r << " " << pixels[i][j].g << " " << pixels[i][j].b << " ";
      }
      file << std::endl;
    }
  }
}

float * Pixmap2::toArray() {
  float * result;

  int count = 0;
  for(int i=0; i<height; i++) {
    for(int j=0; j<width; j++) {
      float x = (float)j/(float)width, y = (float)i/(float)height;
      result[count++] = -1 + (2 * x);
      result[count++] = 1 - (2 * y);
      result[count++] = (float)pixels[i][j].r / (float)max_value;
      result[count++] = (float)pixels[i][j].g / (float)max_value;
      result[count++] = (float)pixels[i][j].b / (float)max_value;
    }
  }

  return result;
}
