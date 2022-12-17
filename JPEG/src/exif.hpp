#ifndef EXIF_HPP
#define EXIF_HPP

#include "jpeg_file.hpp"

class Exif : public JpegFile {
private:
    SOI soi;
    SOF0 sof0;
    DHT dht;
    DQT dqt;
    DRI dri;
    SOS sos;
    JFIF_APP0 app0;
    JFXX_APP0 app1;
    COM com;
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
