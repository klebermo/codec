#ifndef PIXEL_HPP
#define PIXEL_HPP

// RGB pixel struct
struct RgbPixel {
  float r, g, b;

  std::vector<unsigned char> data() {
    std::vector<unsigned char> d;
    d.push_back((unsigned char)(r * 255));
    d.push_back((unsigned char)(g * 255));
    d.push_back((unsigned char)(b * 255));
    return d;
  }

  RgbPixel operator=(unsigned char data[3]) {
    r = data[0] / 255.0f;
    g = data[1] / 255.0f;
    b = data[2] / 255.0f;
    return *this;
  }
};

// YCbCr pixel struct
struct YCbCrPixel {
  float y, cb, cr;

  std::vector<unsigned char> data() {
    std::vector<unsigned char> d;
    d.push_back((unsigned char)(y * 255));
    d.push_back((unsigned char)(cb * 255));
    d.push_back((unsigned char)(cr * 255));
    return d;
  }

  YCbCrPixel operator=(unsigned char data[3]) {
    y = data[0] / 255.0f;
    cb = data[1] / 255.0f;
    cr = data[2] / 255.0f;
    return *this;
  }
};

RgbPixel YCbCrToRgb(const YCbCrPixel& ycbcr);
YCbCrPixel RgbToYCbCr(const RgbPixel& rgb);

#endif
