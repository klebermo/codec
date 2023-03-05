#include "jfif.hpp"

void Jfif::read(std::string filename) {
    std::cout << "Reading " << filename << std::endl;
    std::ifstream file(filename, std::ios::binary);

    if(!file.is_open()) {
        return;
    }

    unsigned char marker[2], length[2];
    int size;

    APP0 app0_temp;
    SOF0 sof0_temp;
    SOF2 sof2_temp;
    DHT dht_temp;
    DQT dqt_temp;
    DRI dri_temp;
    COM com_temp;
    SOS sos_temp;

    while(file.read((char*)marker, 2)) {
        if(marker[0] == 0xFF) {
            switch(marker[1]) {
                case 0xD8: // SOI
                    std::cout << "SOI" << std::endl;
                    break;
                case 0xE0: // APP0
                    std::cout << "APP0" << std::endl;

                    file.read((char*)length, 2);
                    size = (length[0] << 8) | length[1];
                    size = size - 2;

                    file.read(reinterpret_cast<char*>(&app0_temp), size);
                    break;
                case 0xC0: // SOF0
                    std::cout << "SOF0" << std::endl;

                    file.read((char*)length, 2);
                    size = (length[0] << 8) | length[1];
                    size = size - 2;

                    file.read(reinterpret_cast<char*>(&sof0_temp), size);
                    break;
                case 0xC2: // SOF2
                    std::cout << "SOF2" << std::endl;

                    file.read((char*)length, 2);
                    size = (length[0] << 8) | length[1];
                    size = size - 2;

                    file.read(reinterpret_cast<char*>(&sof2_temp), size);
                    break;
                case 0xC4: // DHT
                    std::cout << "DHT" << std::endl;

                    file.read((char*)length, 2);
                    size = (length[0] << 8) | length[1];
                    size = size - 2;

                    file.read(reinterpret_cast<char*>(&dht_temp), size);
                    //dht.push_back(dht_temp);
                    break;
                case 0xDB: // DQT
                    std::cout << "DQT" << std::endl;

                    file.read((char*)length, 2);
                    size = (length[0] << 8) | length[1];
                    size = size - 2;

                    file.read(reinterpret_cast<char*>(&dqt_temp), size);
                    //dqt.push_back(dqt_temp);
                    break;
                case 0xDD: // DRI
                    std::cout << "DRI" << std::endl;

                    file.read((char*)length, 2);
                    size = (length[0] << 8) | length[1];
                    size = size - 2;

                    file.read(reinterpret_cast<char*>(&dri_temp), size);
                    break;
                case 0xFE: // COM
                    std::cout << "COM" << std::endl;

                    file.read((char*)length, 2);
                    size = (length[0] << 8) | length[1];
                    size = size - 2;

                    file.read(reinterpret_cast<char*>(&com_temp), size);
                    break;
                case 0xDA: // SOS
                    std::cout << "SOS" << std::endl;

                    file.read((char*)length, 2);
                    size = (length[0] << 8) | length[1];
                    size = size - 2;

                    file.read(reinterpret_cast<char*>(&sos_temp), size);
                    //sos.push_back(sos_temp);
                    break;
                case 0xD9: // EOI
                    std::cout << "EOI" << std::endl;
                    break;
                default:
                    std::cout << "Unknown marker: " << std::hex << (int)marker[1] << std::endl;
                    break;
            }
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
