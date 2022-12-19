#ifndef PIXEL_HPP
#define PIXEL_HPP

// RGB pixel struct
struct RgbPixel {
  float r, g, b;

  bool operator==(const RgbPixel& other) const {
    return r == other.r && g == other.g && b == other.b;
  }

  bool operator<(const RgbPixel& other) const {
    return r < other.r && g < other.g && b < other.b;
  }

  bool operator>(const RgbPixel& other) const {
    return r > other.r && g > other.g && b > other.b;
  }
};

// YCbCr pixel struct
struct YCbCrPixel {
  float y, cb, cr;

  bool operator==(const YCbCrPixel& other) const {
    return y == other.y && cb == other.cb && cr == other.cr;
  }

  bool operator<(const YCbCrPixel& other) const {
    return y < other.y && cb < other.cb && cr < other.cr;
  }

  bool operator>(const YCbCrPixel& other) const {
    return y > other.y && cb > other.cb && cr > other.cr;
  }
};

RgbPixel YCbCrToRgb(const YCbCrPixel& ycbcr);
YCbCrPixel RgbToYCbCr(const RgbPixel& rgb);

#endif
