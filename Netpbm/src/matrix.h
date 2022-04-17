#ifndef MATRIX_H
#define MATRIX_H

template<class T>
class Matrix
{
protected:
    int width;
    int height;
    T ** values;
public:
    Matrix(int width, int height);
    ~Matrix();

    T get(int i, int j);
    void set(int i, int j, T value);

    int getWidth();
    int getHeight();
};

template<class T>
Matrix<T>::Matrix(int width, int height) {
  this->width = width;
  this->height = height;

  values = new T*[height];
  for(int i=0; i<height; i++)
    values[i] = new T[width];
}

template<class T>
Matrix<T>::~Matrix() {
  for(int i=0; i<height; i++)
    delete [] values[i];
  delete [] values;
}

template<class T>
T Matrix<T>::get(int i, int j) {
  return values[i][j];
}

template<class T>
void Matrix<T>::set(int i, int j, T value) {
  values[i][j] = value;
}

template<class T>
int Matrix<T>::getWidth() {
  return width;
}

template<class T>
int Matrix<T>::getHeight() {
  return height;
}

#endif //MATRIX_H
