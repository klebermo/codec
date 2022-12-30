#include "jfif.hpp"

void Jfif::readFile(std::string filename) {
    std::ifstream file(filename, std::ios::binary);

    if(!file.is_open()) {
        return;
    }
}

void Jfif::writeFile(std::string filename) {
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
