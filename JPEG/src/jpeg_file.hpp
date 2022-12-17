#ifndef JPEG_FILE_HPP
#define JPEG_FILE_HPP

#include "jpeg_segments.hpp"

class JpegFile {
private:
    Matrix<RgbPixel> pixels;
public:
    virtual bool encode() = 0;
    virtual bool decode() = 0;

    virtual bool readFile(std::string filename) = 0;
    virtual bool writeFile(std::string filename, Matrix<RgbPixel> pixels) = 0;

    virtual int getWidth() = 0;
    virtual int getHeight() = 0;

    std::vector<float> toArray();
};

#endif
