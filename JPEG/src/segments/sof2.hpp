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
  SOF2() : Segment({0xFF, 0xC2}, 20) {}
  
  unsigned char getSamplePrecision() {
    return sample_precision;
  }

  unsigned char getImageHeight() {
    return image_height;
  }

  unsigned char getImageWidth() {
    return image_width;
  }

  unsigned char getComponentCount() {
    return component_count;
  }

  unsigned char * getComponentId() {
    return component_id;
  }

  unsigned char * getHorizontalSamplingFactor() {
    return horizontal_sampling_factor;
  }

  unsigned char * getVerticalSamplingFactor() {
    return vertical_sampling_factor;
  }

  unsigned char * getQuantizationTable () {
    return quantization_table_selector;
  }

  void setData(unsigned char * data, int data_length) override {
    sample_precision = data[0];
    image_height = data[1];
    image_width = data[2];
    component_count = data[3];
    for (int i = 0; i < 4; i++) {
      component_id[i] = data[i * 3 + 4];
      horizontal_sampling_factor[i] = data[i * 3 + 5];
      vertical_sampling_factor[i] = data[i * 3 + 6];
      quantization_table_selector[i] = data[i * 3 + 7];
    }
  }
};

#endif
