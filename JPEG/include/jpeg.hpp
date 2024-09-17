#include <vector>
#include <string>

#ifndef PIXEL_H
#define PIXEL_H

struct Pixel {
  float r, g, b;
};
typedef struct Pixel Pixel;

#endif

#ifndef JPEG_H
#define JPEG_H

template<class T> class Matrix {};

class JPEG {
protected:
  Matrix<Pixel> pixels;
public:
  void read(std::string filename);
  void write(std::string filename);

  int getWidth();
  int getHeight();

  std::vector<float> toArray();
};

#endif
