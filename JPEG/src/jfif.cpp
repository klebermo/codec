#include "jfif.hpp"

void Jfif::read(std::string filename) {
    std::cout << "Reading " << filename << std::endl;
    std::ifstream file(filename, std::ios::binary);

    if(!file.is_open()) {
        return;
    }

    unsigned char marker[2], length[2];
    int size;
    APP * app_temp;
    DHT dht_temp;
    DQT dqt_temp;
    SOS sos_temp;

    while(file.read((char*)marker, 2)) {
        file.read((char*)length, 2);
        size = (length[0] << 8) | length[1];
        size = size - 2;

        if(marker[0] == 0xFF) {
            switch(marker[1]) {
                case 0xD8: // SOI
                    std::cout << "SOI" << std::endl;
                    break;
                case 0xE0: // APP0
                    std::cout << "APP0" << std::endl;
                    app_temp = new APP0();
                    file.read(reinterpret_cast<char*>(app_temp), size);
                    delete app_temp;
                    break;
                case 0xE1: // APP1
                    std::cout << "APP1" << std::endl;
                    app_temp = new APP1();
                    file.read(reinterpret_cast<char*>(app_temp), size);
                    delete app_temp;
                    break;
                case 0xE2: // APP2
                    std::cout << "APP2" << std::endl;
                    app_temp = new APP2(size);
                    file.read(reinterpret_cast<char*>(app_temp), size);
                    delete app_temp;
                    break;
                case 0xE3: // APP3
                    std::cout << "APP3" << std::endl;
                    app_temp = new APP3(size);
                    file.read(reinterpret_cast<char*>(app_temp), size);
                    delete app_temp;
                    break;
                case 0xE4: // APP4
                    std::cout << "APP4" << std::endl;
                    app_temp = new APP4(size);
                    file.read(reinterpret_cast<char*>(app_temp), size);
                    delete app_temp;
                    break;
                case 0xE5: // APP5
                    std::cout << "APP5" << std::endl;
                    app_temp = new APP5(size);
                    file.read(reinterpret_cast<char*>(app_temp), size);
                    delete app_temp;
                    break;
                case 0xE6: // APP6
                    std::cout << "APP6" << std::endl;
                    app_temp = new APP6(size);
                    file.read(reinterpret_cast<char*>(app_temp), size);
                    delete app_temp;
                    break;
                case 0xE7: // APP7
                    std::cout << "APP7" << std::endl;
                    app_temp = new APP7(size);
                    file.read(reinterpret_cast<char*>(app_temp), size);
                    delete app_temp;
                    break;
                case 0xE8: // APP8
                    std::cout << "APP8" << std::endl;
                    app_temp = new APP8(size);
                    file.read(reinterpret_cast<char*>(app_temp), size);
                    delete app_temp;
                    break;
                case 0xE9: // APP9
                    std::cout << "APP9" << std::endl;
                    app_temp = new APP9(size);
                    file.read(reinterpret_cast<char*>(app_temp), size);
                    delete app_temp;
                    break;
                case 0xEA: // APP10
                    std::cout << "APP10" << std::endl;
                    app_temp = new APP10(size);
                    file.read(reinterpret_cast<char*>(app_temp), size);
                    delete app_temp;
                    break;
                case 0xEB: // APP11
                    std::cout << "APP11" << std::endl;
                    app_temp = new APP11(size);
                    file.read(reinterpret_cast<char*>(app_temp), size);
                    delete app_temp;
                    break;
                case 0xEC: // APP12
                    std::cout << "APP12" << std::endl;
                    app_temp = new APP12(size);
                    file.read(reinterpret_cast<char*>(app_temp), size);
                    delete app_temp;
                    break;
                case 0xED: // APP13
                    std::cout << "APP13" << std::endl;
                    app_temp = new APP13(size);
                    file.read(reinterpret_cast<char*>(app_temp), size);
                    delete app_temp;
                    break;
                case 0xEE: // APP14
                    std::cout << "APP14" << std::endl;
                    app_temp = new APP14(size);
                    file.read(reinterpret_cast<char*>(app_temp), size);
                    delete app_temp;
                    break;
                case 0xEF: // APP15
                    std::cout << "APP15" << std::endl;
                    app_temp = new APP15(size);
                    file.read(reinterpret_cast<char*>(app_temp), size);
                    delete app_temp;
                    break;
                case 0xC0: // SOF0
                    std::cout << "SOF0" << std::endl;
                    file.read(reinterpret_cast<char*>(&sof0), size);
                    break;
                case 0xC2: // SOF2
                    std::cout << "SOF2" << std::endl;
                    file.read(reinterpret_cast<char*>(&sof2), size);
                    break;
                case 0xC4: // DHT
                    std::cout << "DHT" << std::endl;
                    file.read(reinterpret_cast<char*>(&dht_temp), size);
                    dht.push_back(dht_temp);
                    break;
                case 0xDB: // DQT
                    std::cout << "DQT" << std::endl;
                    file.read(reinterpret_cast<char*>(&dqt_temp), size);
                    dqt.push_back(dqt_temp);
                    break;
                case 0xDD: // DRI
                    std::cout << "DRI" << std::endl;
                    file.read(reinterpret_cast<char*>(&dri), size);
                    break;
                case 0xFE: // COM
                    std::cout << "COM" << std::endl;
                    file.read(reinterpret_cast<char*>(&com), size);
                    break;
                case 0xDA: // SOS
                    std::cout << "SOS" << std::endl;
                    file.read(reinterpret_cast<char*>(&sos_temp), size);
                    sos.push_back(sos_temp);
                    while(file.peek() != 0xFF) {
                        unsigned char scan_data_temp;
                        file.read(reinterpret_cast<char*>(&scan_data_temp), 1);
                    }
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
