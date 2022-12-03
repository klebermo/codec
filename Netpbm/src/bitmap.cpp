#include "bitmap.hpp"

Bitmap::Bitmap(std::string file_name) {
  read_file(file_name);
}

Bitmap::~Bitmap() {
  //
}

void Bitmap::read_file(std::string file_name) {
  std::ifstream file(file_name);
  std::string line_one, line_two, line_pixels;

  while(getline(file, line_one)) {
    if(line_one.size() > 0 && line_one.at(0) != '#') {
      setMagicNumber(line_one.at(1));
      break;
    }
  }

  while(getline(file, line_two)) {
    if(line_two.size() > 0 && line_two.at(0) != '#') {
      std::string width, height;
      std::stringstream ss(line_two);

      if(getline(ss, width, ' '))
        this->setWidth(stoi(width));
      
      if(getline(ss, height, ' '))
        this->setHeight(stoi(height));
      
      break;
    }
  }

  setPixels(new Matrix<pixel>(getHeight(), getWidth()));

  std::cout << "bitmap::read_file" << std::endl;
  std::cout << "magicNumber: " << getMagicNumber() << std::endl;
  std::cout << "width: " << getWidth() << std::endl;
  std::cout << "height: " << getHeight() << std::endl;

  if(getMagicNumber() == '1') {
    std::vector<pixel> v;

    while(getline(file, line_pixels)) {
      if(line_pixels.size() > 0 && line_pixels.at(0) != '#') {
        std::stringstream ss(line_pixels);
        std::string value;
        while(getline(ss, value, ' ')) {
          pixel p;
          p.r = p.g = p.b = stoi(value);
          v.push_back(p);
        }
      }
    }

    int counter = 0;
    for(int i=0; i<getHeight(); i++)
      for(int j=0; j<getWidth(); j++)
        (*getPixels())[i][j] = v[counter++];
  }

  if(getMagicNumber() == '4') {
    std::vector<pixel> v;

    while(!file.eof()) {
      unsigned char data[1];
      file.read((char*)data, 1);
      for(int i=0; i<8; i++) {
        pixel p;
        if(data[0]&(1<<i))
          p.r = p.g = p.b = 1;
        else
          p.r = p.g = p.b = 0;
        v.push_back(p);
      }
    }

    int counter = 0;
    for(int i=0; i<getHeight(); i++)
      for(int j=0; j<getWidth(); j++)
        (*getPixels())[i][j] = v[counter++];
  }
}

void Bitmap::write_file(std::string file_name) {
  if(getMagicNumber() == '1') {
    //
  }

  if(getMagicNumber() == '4') {
    //
  }
}

