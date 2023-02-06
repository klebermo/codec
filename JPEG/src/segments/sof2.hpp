#ifndef SOF2_H
#define SOF2_H

class SOF2 {
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
  SOF2() {
    sample_precision = 0x00;
    image_height = 0x00;
    image_width = 0x00;
    component_count = 0x00;
    for (int i = 0; i < 4; i++) {
      component_id[i] = 0x00;
      horizontal_sampling_factor[i] = 0x00;
      vertical_sampling_factor[i] = 0x00;
      quantization_table_selector[i] = 0x00;
    }
  }

  SOF2(unsigned char * data) {
    sample_precision = data[0];
    image_height = data[1];
    image_width = data[2];
    component_count = data[3];
    for (int i = 0; i < 4; i++) {
      component_id[i] = data[4 + (i * 3)];
      horizontal_sampling_factor[i] = data[5 + (i * 3)];
      vertical_sampling_factor[i] = data[6 + (i * 3)];
      quantization_table_selector[i] = data[7 + (i * 3)];
    }
  }

  SOF2& operator=(unsigned char * data) {
    sample_precision = data[0];
    image_height = data[1];
    image_width = data[2];
    component_count = data[3];
    for (int i = 0; i < 4; i++) {
      component_id[i] = data[4 + (i * 3)];
      horizontal_sampling_factor[i] = data[5 + (i * 3)];
      vertical_sampling_factor[i] = data[6 + (i * 3)];
      quantization_table_selector[i] = data[7 + (i * 3)];
    }
    return *this;
  }

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
};

#endif
