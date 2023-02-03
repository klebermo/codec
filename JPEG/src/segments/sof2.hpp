#ifndef SOF2_H
#define SOF2_H

class SOF2 {
public:
  unsigned char sample_precision;
  unsigned char image_height;
  unsigned char image_width;
  unsigned char component_count;
  unsigned char component_id[4];
  unsigned char horizontal_sampling_factor[4];
  unsigned char vertical_sampling_factor[4];
  unsigned char quantization_table_selector[4];
};

#endif
