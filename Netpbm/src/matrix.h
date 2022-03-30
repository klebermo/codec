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

  this->values = new T*[height];
  for(int i=0; i<this->height; i++)
    this->values[i] = new T[width];
}

template<class T>
Matrix<T>::~Matrix() {
  for(int i=0; i<this->height; i++)
    delete [] this->values[i];
  delete [] this->values;
}

template<class T>
T Matrix<T>::get(int i, int j) {
  return this->values[i][j];
}

template<class T>
void Matrix<T>::set(int i, int j, T value) {
  this->values[i][j] = value;
}

template<class T>
int Matrix<T>::getWidth() {
  return this->width;
}

template<class T>
int Matrix<T>::getHeight() {
  return this->height;
}

#endif //MATRIX_H
