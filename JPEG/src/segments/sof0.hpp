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

  void setIdentifier(unsigned char identifier) {
    this->identifier = identifier;
  }

  unsigned char getSamplingFactor() {
    return sampling_factor;
  }

  void setSamplingFactor(unsigned char sampling_factor) {
    this->sampling_factor = sampling_factor;
  }

  unsigned char getQuantizationTable() {
    return quantization_table;
  }

  void setQuantizationTable(unsigned char quantization_table) {
    this->quantization_table = quantization_table;
  }
};

class SOF0 : public Segment {
private:
    unsigned char width;
    unsigned char height;
    unsigned char precision;
    Component components[3];
public:
    SOF0() : Segment({0xFF, 0xC0}, 13) {}
    
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

    void setData(unsigned char * data, int data_length) override {
      height = data[0];
      width = data[1];
      precision = data[2];
      for (int i = 0; i < 3; i++) {
        components[i].setIdentifier(data[i * 3 + 3]);
        components[i].setSamplingFactor(data[i * 3 + 4]);
        components[i].setQuantizationTable(data[i * 3 + 5]);
      }
    }
};

#endif
