#ifndef JPEG_FILE_HPP
#define JPEG_FILE_HPP

#include "jpeg_segments.hpp"

class JpegFile {
private:
    Matrix<RgbPixel> pixels;
public:   
    virtual void readFile(std::string filename) = 0;
    virtual void writeFile(std::string filename, Matrix<RgbPixel> pixels) = 0;

    virtual int getWidth() = 0;
    virtual int getHeight() = 0;

    std::vector<float> toArray();
};

#endif
