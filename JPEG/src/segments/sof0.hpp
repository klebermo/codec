#ifndef SOF0_H
#define SOF0_H

class Component {
public:
  unsigned char identifier;
  unsigned char sampling_factor;
  unsigned char quantization_table;
};

class SOF0 {
public:
    unsigned char width;
    unsigned char height;
    unsigned char precision;
    Component components[3];
};

#endif
