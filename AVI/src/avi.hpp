#ifndef JPEG_H
#define JPEG_H

#include <string>
#include <vector>

struct Pixel {
  float r, g, b;
};
typedef struct Pixel Pixel;

template<class T>
class Matrix {
private:
  T **matrix;
  int height, width;
public:
  Matrix(int height, int width) {
    this->height = height;
    this->width = width;

    matrix = new T*[height];
    for(int i=0; i<height; i++) {
      matrix[i] = new T[width];
    }
  }

  T* operator[](int i) {
    return matrix[i];
  }

  int getHeight() {
    return height;
  }

  int getWidth() {
    return width;
  }
};

class AVI {
protected:
    std::vector<Matrix<Pixel>> pixels;
public:
    void read(std::string filename);
    void write(std::string filename);

    int getFrameCount();
    int getFrameRate();
    int getWidth();
    int getHeight();

  std::vector<float> toArray();
};

#endif
