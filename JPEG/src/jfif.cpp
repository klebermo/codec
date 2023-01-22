#include "jfif.hpp"

void Jfif::read(std::string filename) {
    std::ifstream file(filename, std::ios::binary);

    if(!file.is_open()) {
        return;
    }
}

void Jfif::write(std::string filename) {
    std::ofstream file(filename, std::ios::binary);

    if(!file.is_open()) {
        return;
    }
}

int Jfif::getWidth() {
    return pixels.getWidth();
}

int Jfif::getHeight() {
    return pixels.getHeight();
}
