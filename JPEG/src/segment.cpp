#include "segment.hpp"

Segment::Segment(unsigned char marker[2], unsigned char length[2])  {
        this->marker[0] = marker[0];
        this->marker[1] = marker[1];
        this->length[0] = length[0];
        this->length[1] = length[1];
};

Segment::segment(std::initializer_list<unsigned char> marker, std::initializer_list<unsigned char> length) {
    this->marker[0] = marker[0];
    this->marker[1] = marker[1];
    this->length[0] = length[0];
    this->length[1] = length[1];
}

Segment::Segment(unsigned char marker[2], int length) {
    this->marker[0] = marker[0];
    this->marker[1] = marker[1];
    this->length = intToUnsignedCharArr(length);
}

Segment::Segment(std::initializer_list<unsigned char> marker, int length) {
    this->marker[0] = marker[0];
    this->marker[1] = marker[1];
    this->length = intToUnsignedCharArr(length);
}

unsigned char * Segment::getMarker() {
    return marker;
}

unsigned char * Segment::getLength() {
    return length;
}

void Segment::setLength(unsigned char length[2]) {
    this->length[0] = length[0];
    this->length[1] = length[1];
}

void Segment::intToUnsignedCharArr(int value, unsigned char result[2]) {
    result[0] = (unsigned char) ((value >> 8) & 0xFF); // upper 8 bits
    result[1] = (unsigned char) (value & 0xFF); // lower 8 bits
}
