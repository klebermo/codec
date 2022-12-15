#ifndef JPEG_FILE_HPP
#define JPEG_FILE_HPP

#include "jpeg_segments.hpp"

class JpegFile {
public:   
    virtual void readFile(std::string filename) = 0;
    virtual void writeFile(std::string filename) = 0;

    std::vector<float> toArray();
};

#endif
