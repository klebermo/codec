#include "graymap.hpp"

Graymap::Graymap(std::string file_name) {
  this->read_file(file_name);
}

Graymap::~Graymap() {
  for (int i = 0; i < this->height; i++)
    delete[] pixels[i];
  delete[] pixels;
}

void Graymap::read_file(std::string file_name) {
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

  pixels = new int*[height];
  for(int i=0; i<height; i++) {
    pixels[i] = new int[width];
  }

  if(this->magicNumber == "P2") {
    //
  }

  if(this->magicNumber == "P5") {
    //
  }
}

void Graymap::write_file(std::string file_name) {
  std::ofstream file(file_name);
  file << magicNumber << std::endl;
  file << width << " " << height << std::endl;
  file << max_value << std::endl;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if(magicNumber == "P2") {
        file << pixels[i][j] << " ";
      } else {
        file << pixels[i][j];
      }
    }
    file << std:: endl;
  }
}

float * Graymap::toArray() {
  float * result = new float[width * height * 5];

  int count = 0;
  for(int i=0; i<height; i++) {
    for(int j=0; j<width; j++) {
      float x = (float)j/(float)width, y = (float)i/(float)height;
      result[count++] = -1 + (2 * x);
      result[count++] = 1 - (2 * y);
      result[count++] = (float)pixels[i][j] / (float)max_value;
      result[count++] = (float)pixels[i][j] / (float)max_value;
      result[count++] = (float)pixels[i][j] / (float)max_value;
    }
  }

  return result;
}
