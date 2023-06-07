#ifndef COM_H
#define COM_H

#include "../segment.hpp"

class COM : public Segment {
private:
    unsigned char * comment;
public:
    COM() : Segment({0xFF, 0xFE}, {0x00, 0x00}) {}
    ~COM() {
        delete[] this->comment;
    }
    void setData(unsigned char * data, int size) {
        this->comment = new unsigned char[size];
        for (int i = 0; i < size; i++) {
            this->comment[i] = data[i];
        }
    }
};

#endif
