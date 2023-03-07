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

unsigned char * Segment::getMarker() {
    return marker;
}

unsigned char * Segment::getLength() {
    return length;
}

void Segment::read(std::ifstream &file) {
    unsigned char marker[2], length[2];

    while(file.read((char*)marker, 2)) {
        if(marker[0] == 0xFF) {
            file.read((char*)length, 2);
        }
    }
}

void Segment::write(std::ofstream &file) {
    file.write((char*)marker, 2);
    file.write((char*)length, 2);
}
