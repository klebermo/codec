#include "segment.hpp"

Segment::Segment(unsigned char marker[2], unsigned char length[2])  {
        this->marker[0] = marker[0];
        this->marker[1] = marker[1];
        this->length[0] = length[0];
        this->length[1] = length[1];
};

Segment::Segment(std::initializer_list<unsigned char> marker_list, std::initializer_list<unsigned char> length_list) {
    int m_size = marker_list.size();
    int index = 0;
    for(auto it : marker_list) {
        unsigned char data = (unsigned char)it;
        this->marker[index++] = data;
    }

    int l_size = length_list.size();
    index = 0;
    for(auto it : length_list) {
        unsigned char data = (unsigned char)it;
        this->length[index++] = data;
    }
}

Segment::Segment(unsigned char marker[2], int length) {
    this->marker[0] = marker[0];
    this->marker[1] = marker[1];

    unsigned char length_str[2];
    intToUnsignedCharArr(length, length_str);

    this->length[0] = length_str[0];
    this->length[1] = length_str[1];
}

Segment::Segment(std::initializer_list<unsigned char> marker_list, int length) {
    int m_size = marker_list.size();
    int index = 0;
    for(auto it : marker_list) {
        unsigned char data = (unsigned char)it;
        this->marker[index++] = data;
    }

    unsigned char length_str[2];
    intToUnsignedCharArr(length, length_str);

    this->length[0] = length_str[0];
    this->length[1] = length_str[1];
}

unsigned char * Segment::getMarker() {
    return marker;
}

void Segment::setMarker(unsigned char marker[2]) {
    this->marker[0] = marker[0];
    this->marker[1] = marker[1];
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
