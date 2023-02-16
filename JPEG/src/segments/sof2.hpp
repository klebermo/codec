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
