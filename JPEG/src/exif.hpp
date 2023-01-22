#ifndef EXIF_HPP
#define EXIF_HPP

#include "jpeg.hpp"

class Exif : public JPEG {
private:
    //
public:
    void read(std::string filename);
    void write(std::string filename);

    int getWidth();
    int getHeight();
};

#endif
