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
  SOS() : Segment({0xFF, 0xDA}, 16) {}
  
  unsigned char getComponentCount() {
    return component_count;
  }

  unsigned char * getComponentId() {
    return component_id;
  }

  unsigned char * getHuffmanTableSelector() {
    return huffman_table_selector;
  }

  unsigned char getStartOfSpectralSelection() {
    return start_of_spectral_selection;
  }

  unsigned char getEndOfSpectralSelection() {
    return end_of_spectral_selection;
  }

  unsigned char getSuccessiveApproximation() {
    return successive_approximation;
  }

  void setData(unsigned char * data, int data_length) override {
    component_count = data[0];
    for (int i = 0; i < 4; i++) {
      component_id[i] = data[i * 2 + 1];
      huffman_table_selector[i] = data[i * 2 + 2];
    }
    start_of_spectral_selection = data[9];
    end_of_spectral_selection = data[10];
    successive_approximation = data[11];
  }
};

#endif
