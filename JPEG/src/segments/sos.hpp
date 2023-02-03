#ifndef SOS_H
#define SOS_H

class SOS {
public:
  unsigned char component_count;
  unsigned char component_id[4];
  unsigned char huffman_table_selector[4];
  unsigned char start_of_spectral_selection;
  unsigned char end_of_spectral_selection;
  unsigned char successive_approximation;
};

#endif
