#ifndef JFIF_HPP
#define JFIF_HPP

#include "jpeg_file.hpp"

class JFIF : public JpegFile {
private:
    SOI soi;
    JFIF_APP0 jfif_app0;
    JFXX_APP0 jfxx_app0;
    SOF0 sof0;
    DHT dht;
    COM com;
    SOS sos;
    EOI eoi;
public:
    void readFile(std::string filename);
    void writeFile(std::string filename);
};

#endif
