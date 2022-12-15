#ifndef PIXEL_HPP
#define PIXEL_HPP

// RGB pixel struct
struct RgbPixel {
  float r, g, b;
};

// YCbCr pixel struct
struct YCbCrPixel {
  float y, cb, cr;
};

RgbPixel YCbCrToRgb(const YCbCrPixel& ycbcr);
YCbCrPixel RgbToYCbCr(const RgbPixel& rgb);

#endif
