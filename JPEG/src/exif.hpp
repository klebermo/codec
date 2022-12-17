#ifndef EXIF_HPP
#define EXIF_HPP

#include "jpeg_file.hpp"

class Exif : public JpegFile {
private:
    SOI soi;
    SOF0 sof0;
    SOF2 sof2;
    DHT dht;
    DQT dqt;
    DRI dri;
    SOS sos;
    APP0 app0;
    APP1 app1;
    COM com;
    EOI eoi;
public:
    void readFile(std::string filename);
    void writeFile(std::string filename, Matrix<RgbPixel> pixels);

    int getWidth();
    int getHeight();
};

#endif
