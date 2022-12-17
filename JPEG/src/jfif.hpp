#ifndef JFIF_HPP
#define JFIF_HPP

#include "jpeg_file.hpp"

class Jfif : public JpegFile {
private:
    SOI soi;
    SOF0 sof0;
    DQT dqt;
    DHT dht;
    JFIF_APP0 app0;
    JFXX_APP0 app1;
    COM com;
    DRI dri;
    SOS sos;
    std::vector<unsigned char> compressed_data;
    EOI eoi;
public:
    bool encode();
    bool decode();

    bool readFile(std::string filename);
    bool writeFile(std::string filename, Matrix<RgbPixel> pixels);

    int getWidth();
    int getHeight();
};

#endif
