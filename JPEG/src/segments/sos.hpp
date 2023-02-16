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
