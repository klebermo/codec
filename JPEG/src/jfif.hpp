#ifndef JFIF_HPP
#define JFIF_HPP

#include "jpeg.hpp"

#include "segments/app.hpp"
#include "segments/sof0.hpp"
#include "segments/sof2.hpp"
#include "segments/dqt.hpp"
#include "segments/dht.hpp"
#include "segments/dri.hpp"
#include "segments/com.hpp"
#include "segments/sos.hpp"

#include <iostream>

class Jfif : public JPEG {
private:
    std::map<int,APP> app;
    SOF0 sof0;
    SOF2 sof2;
    std::vector<DQT> dqt;
    std::vector<DHT> dht;
    DRI dri;
    COM com;
    std::vector<SOS> sos;
public:
    void read(std::string filename);
    void write(std::string filename);

    int getWidth();
    int getHeight();
};

#endif
