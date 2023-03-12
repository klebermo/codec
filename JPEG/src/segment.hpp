#ifndef SEGMENT_HPP
#define SEGMENT_HPP

#include <initializer_list>

class Segment {
protected:
    unsigned char marker[2];
    unsigned char length[2];
public:
    Segment(unsigned char marker[2], unsigned char length[2]);

    Segment(std::initializer_list<unsigned char> marker, std::initializer_list<unsigned char> length);

    Segment(unsigned char marker[2], int length);

    Segment(std::initializer_list<unsigned char> marker, int length);

    unsigned char * getMarker();

    unsigned char * getLength();

    void setLength(unsigned char length[2]);

    virtual void setData(unsigned char * data, int data_length) = 0;

    void intToUnsignedCharArr(int value, unsigned char result[2]);
};

#endif
