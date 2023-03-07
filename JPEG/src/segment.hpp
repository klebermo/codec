#ifndef SEGMENT_HPP
#define SEGMENT_HPP

#include <initializer_list>

class Segment {
private:
    unsigned char marker[2];
    unsigned char length[2];
public:
    Segment(unsigned char marker[2], unsigned char length[2]);

    Segment(std::initializer_list<unsigned char> marker, std::initializer_list<unsigned char> length);

    unsigned char * getMarker();

    unsigned char * getLength();

    void read(std::ifstream & file);

    void write(std::ofstream & file);
};

#endif
