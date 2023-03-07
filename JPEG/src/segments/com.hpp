#ifndef COM_H
#define COM_H

#include "../segment.hpp"

class COM : public Segment {
private:
    unsigned char comment[65535];
public:
    COM() : Segment({0xFF, 0xFE}, {0x00, 0x00}) {}

    unsigned char * getComment() {
        return comment;
    }
};

#endif
