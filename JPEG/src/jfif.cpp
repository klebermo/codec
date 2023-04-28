#include "jfif.hpp"

void Jfif::read(std::string filename) {
    std::cout << "Reading " << filename << std::endl;
    std::ifstream file(filename, std::ios::binary);

    if(!file.is_open()) {
        return;
    }

    unsigned char marker[2], length[2];

    while(file.read((char*)marker, 2)) {
        if(marker[0] == 0xFF) {
            file.read((char*)length, 2);
            int value = (length[1] << 8) | length[0];
            value = value - 2;

            std::cout << "marker: " << std::hex << (int)marker[0] << " " << (int)marker[1] << std::endl;
            std::cout << "length: " << std::hex << (int)length[0] << " " << (int)length[1] << std::endl;
            std::cout << "value: " << value << std::endl;

            unsigned char * data = new unsigned char(value);
            file.read((char*)data, value);

            switch(marker[1]) {
                case 0xD8:
                    std::cout << "SOI" << std::endl;
                    break;
                case 0xE0:
                case 0xE1:
                case 0xE2:
                case 0xE3:
                case 0xE4:
                case 0xE5:
                case 0xE6:
                case 0xE7:
                case 0xE8:
                case 0xE9:
                case 0xEA:
                case 0xEB:
                case 0xEC:
                case 0xED:
                case 0xEE:
                case 0xEF:
                    std::cout << "APP" << std::endl;
                    break;
                case 0xC0:
                    std::cout << "SOF0" << std::endl;
                    break;
                case 0xC2:
                    std::cout << "SOF2" << std::endl;
                    break;
                case 0xC4:
                    std::cout << "DHT" << std::endl;
                    break;
                case 0xDB:
                    std::cout << "DQT" << std::endl;
                    break;
                case 0xDD:
                    std::cout << "DRI" << std::endl;
                    break;
                case 0xDA:
                    std::cout << "SOS" << std::endl;
                    break;
                case 0xD9:
                    std::cout << "EOI" << std::endl;
                    break;
                default:
                    std::cout << "Unknown marker: " << marker[1] << std::endl;
                    break;
            }

            delete data;
        }
    }

    file.close();
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
