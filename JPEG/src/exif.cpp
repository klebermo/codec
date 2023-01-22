#include "exif.hpp"

void Exif::read(std::string filename) {
    std::ifstream file(filename, std::ios::binary);

    if(!file.is_open()) {
        return;
    }
}

void Exif::write(std::string filename) {
    std::ofstream file(filename, std::ios::binary);

    if(!file.is_open()) {
        return;
    }
}

int Exif::getWidth() {
    return pixels.getWidth();
}

int Exif::getHeight() {
    return pixels.getHeight();
}
