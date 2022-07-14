#include "graymap.hpp"

Graymap::Graymap(std::string file_name) {
  this->read_file(file_name);
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

  if(this->magicNumber == "P2") {
    std::cout << "P2" << std::endl;
    while(getline(file, line_pixels)) {
      if(line_pixels.at(0) != '#') {
        std::string data;
        std::stringstream ss;

        std::vector<pixel> row;
        while(getline(ss, data, ' ')) {
          pixel p;
          p.r = p.g = p.b = stoi(data) / max_value;
          row.push_back(p);
        }
        pixels.push_back(row);
      }
    }
  }

  if(this->magicNumber == "P5") {
    std::cout << "P5" << std::endl;
    for(int i=0; i < height; i++) {
      std::vector<pixel> row;
      for(int j = 0; j < width; j++) {
        unsigned char c;
        file.read(reinterpret_cast<char*>(&c), sizeof(unsigned char));

        pixel p;
        p.r = p.g = p.b = static_cast<int>(c);

        row.push_back(p);
      }
      pixels.push_back(row);
    }
  }
}

void Graymap::write_file(std::string file_name) {
  std::ofstream file(file_name);

  file << magicNumber << std::endl;
  file << width << " " << height << std::endl;
  file << max_value << std::endl;

  if(this->magicNumber == "P2") {
    //
  }

  if(this->magicNumber == "P5") {
    //
  }
}

float * Graymap::toArray() {
  float * result = new float[width * height * 5];

  int count = 0;
  for(int i=0; i<height; i++) {
    for(int j=0; j<width; j++) {
      float x = static_cast<float>(j)/static_cast<float>(width), y = static_cast<float>(i)/static_cast<float>(height);
      result[count++] = -1 + (2 * x);
      result[count++] = 1 - (2 * y);
      result[count++] = static_cast<float>(pixels[i][j].r) / static_cast<float>(max_value);
      result[count++] = static_cast<float>(pixels[i][j].g) / static_cast<float>(max_value);
      result[count++] = static_cast<float>(pixels[i][j].b) / static_cast<float>(max_value);
    }
  }

  return result;
}
