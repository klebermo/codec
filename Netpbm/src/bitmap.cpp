#include "bitmap.hpp"

Bitmap::Bitmap(std::string file_name) {
  read_file(file_name);
}

void Bitmap::read_file(std::string file_name) {
  std::ifstream file(file_name);
  std::string line_one, line_two, line_pixels;
  
  while(getline(file, line_one)) {
    if(line_one.at(0) != '#') {
      magicNumber = line_one;
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

  if(magicNumber == "P1") {
    std::cout << "P1" << std::endl;
    while(getline(file, line_pixels)) {
      if(line_pixels.at(0) != '#') {
        std::string data;
        std::stringstream ss(line_pixels);
        std::vector<pixel> row;
        while(getline(ss, data, ' ')) {
          pixel p;
          p.r = p.g = p.b = stoi(data);
          row.push_back(p);
        }
        pixels.push_back(row);
      }
    }
  }

  if(magicNumber == "P4") {
    std::cout << "P4" << std::endl;
  }
}

void Bitmap::write_file(std::string file_name) {
  std::ofstream file(file_name);

  file << magicNumber << std::endl;
  file << width << " " << height << std::endl;

  if(magicNumber == "P1") {
    //
  } else {
    //
  }
}

float * Bitmap::toArray() {
  float * result = new float[width * height * 5];

  int count = 0;
  for(float i=0; i<height; i++) {
    for(float j=0; j<width; j++) {
      float x = j/width, y=i/height;
      result[count++] = -1 + (2 * x);
      result[count++] = 1 - (2 * y);
      result[count++] = pixels[i][j].r;
      result[count++] = pixels[i][j].g;
      result[count++] = pixels[i][j].b;
    }
  }

  return result;
}
