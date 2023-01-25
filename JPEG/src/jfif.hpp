#ifndef JFIF_HPP
#define JFIF_HPP

#include "jpeg.hpp"

class Jfif : public JPEG {
private:
    APP0 app0;
    SOF0 sof0;
    SOF2 sof2;
    std::vector<DQT> dqt;
    std::vector<DHT> dht;
    DRI dri;
    COM com;
    std::vector<SOS> sos;
    std::vector<bool> raw_data;
public:
    void read(std::string filename);
    void write(std::string filename);

    int getWidth();
    int getHeight();
};

#endif
