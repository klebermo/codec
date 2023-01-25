#include "jfif.hpp"

void Jfif::read(std::string filename) {
    std::cout << "Reading " << filename << std::endl;
    std::ifstream file(filename, std::ios::binary);

    if(!file.is_open()) {
        return;
    }

    unsigned char marker[2], length[2];
    unsigned char * data;
    int size;
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
                    data = new unsigned char[size-2];
                    file.read(reinterpret_cast<char*>(data), size-2);
                    app0 = data;
                    delete [] data;
                    break;
                case 0xC0: // SOF0
                    std::cout << "SOF0" << std::endl;
                    file.read((char*)length, 2);
                    size = (length[0] << 8) | length[1];
                    data = new unsigned char[size];
                    file.read(reinterpret_cast<char*>(data), size);
                    sof0 = data;
                    delete [] data;
                    break;
                case 0xC2: // SOF2
                    std::cout << "SOF2" << std::endl;
                    file.read((char*)length, 2);
                    size = (length[0] << 8) | length[1];
                    data = new unsigned char[size];
                    file.read(reinterpret_cast<char*>(data), size);
                    sof2 = data;
                    delete [] data;
                    break;
                case 0xC4: // DHT
                    std::cout << "DHT" << std::endl;
                    DHT dht_temp;
                    file.read((char*)length, 2);
                    size = (length[0] << 8) | length[1];
                    data = new unsigned char[size];
                    file.read(reinterpret_cast<char*>(data), size);
                    dht_temp = data;
                    dht.push_back(dht_temp);
                    delete [] data;
                    break;
                case 0xDB: // DQT
                    std::cout << "DQT" << std::endl;
                    DQT dqt_temp;
                    file.read((char*)length, 2);
                    size = (length[0] << 8) | length[1];
                    data = new unsigned char[size];
                    file.read(reinterpret_cast<char*>(data), size);
                    dqt_temp = data;
                    dqt.push_back(dqt_temp);
                    delete [] data;
                    break;
                case 0xDD: // DRI
                    std::cout << "DRI" << std::endl;
                    file.read((char*)length, 2);
                    size = (length[0] << 8) | length[1];
                    data = new unsigned char[size];
                    file.read(reinterpret_cast<char*>(data), size);
                    dri = data;
                    delete [] data;
                    break;
                case 0xFE: // COM
                    std::cout << "COM" << std::endl;
                    file.read((char*)length, 2);
                    size = (length[0] << 8) | length[1];
                    data = new unsigned char[size];
                    file.read(reinterpret_cast<char*>(data), size);
                    com = data;
                    delete [] data;
                    break;
                case 0xDA: // SOS
                    std::cout << "SOS" << std::endl;
                    SOS sos_temp;
                    file.read((char*)length, 2);
                    size = (length[0] << 8) | length[1];
                    data = new unsigned char[size];
                    file.read(reinterpret_cast<char*>(data), size);
                    sos_temp = data;
                    sos.push_back(sos_temp);
                    delete [] data;
                    break;
                case 0xD9: // EOI
                    std::cout << "EOI" << std::endl;
                    break;
                default:
                    break;
            }
        }
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
