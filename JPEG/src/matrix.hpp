#ifndef MATRIX_HPP
#define MATRIX_HPP

template<class T>
class Matrix {
private:
  T **matrix;
  int height, width;
public:
  Matrix() {
    this->matrix = nullptr;
    this->height = this->width = 0;
  }

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

#endif
