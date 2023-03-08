#ifndef SOF0_H
#define SOF0_H

#include "../segment.hpp"

class Component {
private:
  unsigned char identifier;
  unsigned char sampling_factor;
  unsigned char quantization_table;
public:
  unsigned char getIdentifier() {
    return identifier;
  }

  unsigned char getSamplingFactor() {
    return sampling_factor;
  }

  unsigned char getQuantizationTable() {
    return quantization_table;
  }
};

class SOF0 : public Segment {
private:
    unsigned char width;
    unsigned char height;
    unsigned char precision;
    Component components[3];
public:
    SOF0() : Segment({0xFF, 0xC0}, {0x00, 0x00}) {}
    
    unsigned char getWidth() {
      return width;
    }

    unsigned char getHeight() {
      return height;
    }

    unsigned char getPrecision() {
      return precision;
    }

    Component * getComponents() {
      return components;
    }

    void read(std::ifstream &file) override {
        //
    }

    void write (std::ofstream &file) override {
        //
    }
};

#endif
