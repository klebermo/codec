#ifndef SOF0_H
#define SOF0_H

class Component {
private:
  unsigned char identifier;
  unsigned char sampling_factor;
  unsigned char quantization_table;
public:
  Component() {
    identifier = 0x00;
    sampling_factor = 0x00;
    quantization_table = 0x00;
  }

  Component(unsigned char * data) {
    identifier = data[0];
    sampling_factor = data[1];
    quantization_table = data[2];
  }

  Component& operator=(unsigned char * data) {
    identifier = data[0];
    sampling_factor = data[1];
    quantization_table = data[2];
    return *this;
  }

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

class SOF0 {
private:
    unsigned char width;
    unsigned char height;
    unsigned char precision;
    Component components[3];
public:
    SOF0() {
      width = 0x00;
      height = 0x00;
      precision = 0x00;
      for (int i = 0; i < 3; i++) {
        components[i] = Component();
      }
    }

    SOF0(unsigned char * data) {
      width = data[0];
      height = data[1];
      precision = data[2];
      for (int i = 0; i < 3; i++) {
        components[i] = Component(data + 3 + (3 * i));
      }
    }

    SOF0& operator=(unsigned char * data) {
      width = data[0];
      height = data[1];
      precision = data[2];
      for (int i = 0; i < 3; i++) {
        components[i] = Component(data + 3 + (3 * i));
      }
      return *this;
    }

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
};

#endif
