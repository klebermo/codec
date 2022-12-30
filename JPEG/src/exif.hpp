#ifndef EXIF_HPP
#define EXIF_HPP

#include "jpeg.hpp"

class Exif : public JPEG {
private:
    SOI soi;
    JFIF_APP0 app0;
    SOF sof;
    DQT dqt;
    DHT dht;
    COM com;
    SOS sos;
    std::vector<bool> raw_data;
    EOI eoi;
public:
    void readFile(std::string filename);
    void writeFile(std::string filename);

    int getWidth();
    int getHeight();
};

#endif
