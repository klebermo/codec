#ifndef SOF0_H
#define SOF0_H

#include "../segment.hpp"

struct Component {
  unsigned char identifier;
  unsigned char sampling_factor;
  unsigned char quantization_table;
};
typedef struct Component Component;

class SOF0 : public Segment {
private:
    unsigned char width;
    unsigned char height;
    unsigned char precision;
    Component components[3];
public:
    SOF0() : Segment({0xFF, 0xC0}, {0x00, 0x00}) {}
    ~SOF0() {}
    void setData(unsigned char * data, int size) {
        this->precision = data[0];

        this->height = data[1] << 8 | data[2];

        this->width = data[3] << 8 | data[4];

        for (int i = 0; i < 3; i++) {
            this->components[i].identifier = data[5 + 3 * i];
            this->components[i].sampling_factor = data[6 + 3 * i];
            this->components[i].quantization_table = data[7 + 3 * i];
        }
    }
};

#endif
