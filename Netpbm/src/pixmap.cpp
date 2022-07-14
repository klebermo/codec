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
    std::cout << "P3" << std::endl;
    for(int row=0; row < height; row++) {
      getline(file, line_pixels);
      if(line_pixels.at(0) != '#') {
        std::stringstream ss(line_pixels);

        std::vector<pixel> row;
        for(int column=0; column < width; column++) {
          std::string data;
          pixel p;

          getline(ss, data, ' ');
          p.r = stoi(data) / max_value;
          row.push_back(p);

          getline(ss, data, ' ');
          p.g = stoi(data) / max_value;
          row.push_back(p);

          getline(ss, data, ' ');
          p.b = stoi(data) / max_value;
          row.push_back(p);
        }
        pixels.push_back(row);
      }
    }
  }

  if(this->magicNumber == "P6") {
    std::cout << "P6" << std::endl;
    for(int i=0; i<height; i++) {
      std::vector<pixel> row;
      for(int j=0; j < width; j++) {
        unsigned char c;
        pixel p;

        file.read(reinterpret_cast<char*>(&c), sizeof(unsigned char));
        p.r = static_cast<int>(c) / max_value;

        file.read(reinterpret_cast<char*>(&c), sizeof(unsigned char));
        p.g = static_cast<int>(c) / max_value;

        file.read(reinterpret_cast<char*>(&c), sizeof(unsigned char));
        p.b = static_cast<int>(c) / max_value;

        row.push_back(p);
      }
      pixels.push_back(row);
    }
  }
}

void Pixmap2::write_file(std::string file_name) {
  std::ofstream file(file_name);

  file << magicNumber << std::endl;
  file << width << " " << height << std::endl;

  if(this->magicNumber == "P3") {
    //
  }

  if(this->magicNumber == "P6") {
    //
  }
}

float * Pixmap2::toArray() {
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
