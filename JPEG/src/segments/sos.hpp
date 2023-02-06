#ifndef SOS_H
#define SOS_H

class SOS {
private:
  unsigned char component_count;
  unsigned char component_id[4];
  unsigned char huffman_table_selector[4];
  unsigned char start_of_spectral_selection;
  unsigned char end_of_spectral_selection;
  unsigned char successive_approximation;
public:
  SOS() {
    component_count = 0x00;
    for (int i = 0; i < 4; i++) {
      component_id[i] = 0x00;
      huffman_table_selector[i] = 0x00;
    }
    start_of_spectral_selection = 0x00;
    end_of_spectral_selection = 0x00;
    successive_approximation = 0x00;
  }

  SOS(unsigned char * data) {
    component_count = data[0];
    for (int i = 0; i < 4; i++) {
      component_id[i] = data[1 + (i * 2)];
      huffman_table_selector[i] = data[2 + (i * 2)];
    }
    start_of_spectral_selection = data[9];
    end_of_spectral_selection = data[10];
    successive_approximation = data[11];
  }

  SOS& operator=(unsigned char * data) {
    component_count = data[0];
    for (int i = 0; i < 4; i++) {
      component_id[i] = data[1 + (i * 2)];
      huffman_table_selector[i] = data[2 + (i * 2)];
    }
    start_of_spectral_selection = data[9];
    end_of_spectral_selection = data[10];
    successive_approximation = data[11];
    return *this;
  }

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
};

#endif
