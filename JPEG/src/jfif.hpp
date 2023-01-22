#ifndef JFIF_HPP
#define JFIF_HPP

#include "jpeg.hpp"

class Jfif : public JPEG {
private:
    //
public:
    void read(std::string filename);
    void write(std::string filename);

    int getWidth();
    int getHeight();
};

#endif
