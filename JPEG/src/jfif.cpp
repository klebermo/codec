#include "jfif.hpp"

void Jfif::readFile(std::string filename) {
    ifstream file(filename, ios::binary);

    file.read((char*)&soi, sizeof(SOI));
    file.read((char*)&jfif_app0, sizeof(JFIF_APP0));
    file.read((char*)&jfxx_app0, sizeof(JFXX_APP0));
    file.read((char*)&sof0, sizeof(SOF0));
    file.read((char*)&dht, sizeof(DHT));
    file.read((char*)&com, sizeof(COM));
    file.read((char*)&sos, sizeof(SOS));
    file.read((char*)&eoi, sizeof(EOI));
}

void Jfif::writeFile(std::string filename, Matrix<RgbPixel> pixels) {
    //
}

int Jfif::getWidth() {
    return 0;
}

int Jfif::getHeight() {
    return 0;
}
