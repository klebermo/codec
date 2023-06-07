#ifndef SEGMENT_HPP
#define SEGMENT_HPP

#include <initializer_list>

class Segment {
protected:
    unsigned char marker[2];
    unsigned char length[2];
public:
    Segment(std::initializer_list<unsigned char> marker, std::initializer_list<unsigned char> length);
    virtual ~Segment() = 0;

    unsigned char * getMarker();
    unsigned char * getLength();

    virtual void setData(unsigned char * data, int size) = 0;
};

#endif
