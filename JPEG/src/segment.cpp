#include "segment.hpp"

Segment::Segment(std::initializer_list<unsigned char> marker, std::initializer_list<unsigned char> length) {
    int m_size = marker_list.size();

    int i = 0;
    for(auto it : marker) {
        this->marker[i++] = (unsigned char)it;
    }

    i = 0;
    for(auto it : length) {
        this->length[i] = (unsigned char)it;
    }
}

unsigned char * Segment::getMarker() {
    return this->marker;
}

unsigned char * Segment::getLength() {
    return this->length;
}
