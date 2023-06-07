#ifndef SOF2_H
#define SOF2_H

#include "../segment.hpp"

class SOF2 : public Segment {
private:
  unsigned char sample_precision;
  unsigned char image_height;
  unsigned char image_width;
  unsigned char component_count;
  unsigned char component_id[4];
  unsigned char horizontal_sampling_factor[4];
  unsigned char vertical_sampling_factor[4];
  unsigned char quantization_table_selector[4];
public:
  SOF2() : Segment({0xFF, 0xC2}, {0x00, 0x00}) {}
  ~SOF2() {}
  void setData(unsigned char * data, int size) {
    this->sample_precision = data[0];

    this->image_height = data[1] << 8 | data[2];

    this->image_width = data[3] << 8 | data[4];

    this->component_count = data[5];

    for (int i = 0; i < this->component_count; i++) {
      this->component_id[i] = data[6 + 3 * i];
      this->horizontal_sampling_factor[i] = data[7 + 3 * i] >> 4;
      this->vertical_sampling_factor[i] = data[7 + 3 * i] & 0x0F;
      this->quantization_table_selector[i] = data[8 + 3 * i];
    }
  }
};

#endif
