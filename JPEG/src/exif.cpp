#include "exif.hpp"

bool Exif::encode() {
    if(pixels.empty()) {
        return false;
    } else {
        int h = pixels.getHeight();
        int w = pixels.getWidth();
        return true;
    }
}

bool Exif::decode() {
    if(compressed_data.empty()) {
        return false;
    } else {
        int h = getHeight();
        int w = getWidth();
        return true;
    }
}

bool Exif::readFile(std::string filename) {
    std::ifstream file(filename, std::ios::binary);

    if(!file.is_open()) {
        return false;
    }

    unsigned char buffer[2];
    while(file.read((char*)buffer, 2)) {
        if(buffer[0] == 0xFF && buffer[1] == 0xD8) {
            file.seekg(-2, std::ios::cur);
            file.read((char*)&soi, sizeof(SOI));
        }

        if(buffer[0] == 0xFF && buffer[1] == 0xC0) {
            file.seekg(-2, std::ios::cur);
            file.read((char*)&sof0, sizeof(SOF0));
        }

        if(buffer[0] == 0xFF && buffer[1] == 0xC4) {
            file.seekg(-2, std::ios::cur);
            file.read((char*)&dht, sizeof(DHT));
        }

        if(buffer[0] == 0xFF && buffer[1] == 0xDB) {
            file.seekg(-2, std::ios::cur);
            file.read((char*)&dqt, sizeof(DQT));
        }

        if(buffer[0] == 0xFF && buffer[1] == 0xDD) {
            file.seekg(-2, std::ios::cur);
            file.read((char*)&dri, sizeof(DRI));
        }

        if(buffer[0] == 0xFF && buffer[1] == 0xDA) {
            file.seekg(-2, std::ios::cur);
            file.read((char*)&sos, sizeof(SOS));

            // Read the compressed data
            unsigned char marker[2];
            while(file.read((char*)marker, 2)) {
                if(marker[0] == 0xFF && marker[1] == 0xD9) {
                    file.seekg(-2, std::ios::cur);
                    file.read((char*)&eoi, sizeof(EOI));
                    break;
                } else {
                    compressed_data.push_back(marker[0]);
                    compressed_data.push_back(marker[1]);
                }
            }
        }

        if(buffer[0] == 0xFF && buffer[1] == 0xE1) {
            file.seekg(2, std::ios::cur);
            char id[5];
            file.read(id, 5);

            if(id[0] == 'E' && id[1] == 'x' && id[2] == 'i' && id[3] == 'f' && id[4] == '\0') {
                file.seekg(-7, std::ios::cur);
                file.read((char*)&app0, sizeof(JFIF_APP0));
            }
        }

        if(buffer[0] == 0xFF && buffer[1] == 0xFE) {
            file.seekg(-2, std::ios::cur);
            file.read((char*)&com, sizeof(COM));
        }
    }

    return decode();
}

bool Exif::writeFile(std::string filename, Matrix<RgbPixel> pixels) {
    std::ofstream file(filename, std::ios::binary);

    if(!file.is_open()) {
        return false;
    }

    if(pixels.empty()) {
        if(encode()) {
            file.write((char*)&soi, sizeof(SOI));
            file.write((char*)&sof0, sizeof(SOF0));
            file.write((char*)&dht, sizeof(DHT));
            file.write((char*)&dqt, sizeof(DQT));
            file.write((char*)&dri, sizeof(DRI));
            file.write((char*)&sos, sizeof(SOS));
            file.write((char*)&app0, sizeof(JFIF_APP0));
            file.write((char*)&com, sizeof(COM));
            for(std::vector<unsigned char>::size_type i = 0; i < compressed_data.size(); i++)
                file.write((char*)&compressed_data[i], sizeof(unsigned char));
            file.write((char*)&eoi, sizeof(EOI));
            return true;
        }
    }

    return false;
}

int Exif::getWidth() {
    return pixels.getWidth();
}

int Exif::getHeight() {
    return pixels.getHeight();
}
