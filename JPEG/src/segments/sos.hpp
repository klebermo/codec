#ifndef SOS_H
#define SOS_H

#include "../segment.hpp"

class SOS : public Segment {
private:
  unsigned char component_count;
  unsigned char component_id[4];
  unsigned char huffman_table_selector[4];
  unsigned char start_of_spectral_selection;
  unsigned char end_of_spectral_selection;
  unsigned char successive_approximation;
public:
  SOS() : Segment({0xFF, 0xDA}, {0x00, 0x00}) {}
  ~SOS() {}
  void setData(unsigned char * data, int size) {
    this->component_count = data[0];

    for (int i = 0; i < this->component_count; i++) {
      this->component_id[i] = data[1 + 2 * i];
      this->huffman_table_selector[i] = data[2 + 2 * i];
    }

    this->start_of_spectral_selection = data[1 + 2 * this->component_count];

    this->end_of_spectral_selection = data[2 + 2 * this->component_count];

    this->successive_approximation = data[3 + 2 * this->component_count];
  }
};

#endif
