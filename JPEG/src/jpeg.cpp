#include "jpeg.hpp"

void JPEG::read(std::string filename) {
  // Open the file for reading
  std::ifstream file(filename, std::ios::binary);
  if (!file.is_open()) {
    std::cerr << "Error: Could not open file" << std::endl;
    exit(1);
  }

  // Read the first two bytes of the file
  char bytes[2];
  file.read(bytes, 2);

  // Check if the first two bytes are 0xFF 0xD8, which indicates that this is a JPEG file
  if (bytes[0] == (char)0xFF && bytes[1] == (char)0xD8) {
    // Read the next two bytes to determine if this is a JFIF or EXIF file
    file.read(bytes, 2);

    if (bytes[0] == (char)0xFF && bytes[1] == (char)0xE0) {
      std::cout << "This is a JFIF file" << std::endl;
      this->jpeg_file = new Jfif();
    } else if (bytes[0] == (char)0xFF && bytes[1] == (char)0xE1) {
      std::cout << "This is an EXIF file" << std::endl;
      this->jpeg_file = new Exif();
    } else {
      std::cout << "This is a JPEG file, but not a JFIF or EXIF file" << std::endl;
      exit(1);
    }
  } else {
    std::cout << "This is not a JPEG file" << std::endl;
    exit(1);
  }

  this->jpeg_file->readFile(filename);
}

void JPEG::write(std::string filename, Matrix<RgbPixel> pixels, jpeg_type type) {
  if(type == JFIF) {
    this->jpeg_file = new Jfif();
  } else {
    this->jpeg_file = new Exif();
  }

  this->jpeg_file->writeFile(filename, pixels);
}

int JPEG::getWidth() {
  return this->jpeg_file->getWidth();
}

int JPEG::getHeight() {
  return this->jpeg_file->getHeight();
}

std::vector<float> JPEG::toArray() {
  return this->jpeg_file->toArray();
}
