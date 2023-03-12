#ifndef COM_H
#define COM_H

#include "../segment.hpp"

class COM : public Segment {
private:
    unsigned char * comment;
public:
    COM() : Segment({0xFF, 0xFE}, 0) {}

    unsigned char * getComment() {
        return comment;
    }

    void setData(unsigned char * data, int data_length) override {
        intToUnsignedCharArr(data_length, length);
        comment = data;
    }
};

#endif
