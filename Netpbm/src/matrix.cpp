#include "matrix.h"

template<class T>
Matrix<T>::Matrix(int width, int height) {
  this->width = width;
  this->height = height;

  this->values = new T*[width];
  for(int i=0; i<width; i++)
    this->values[i] = new T[height];

  for(int i=0; i<width; i++)
    for(int j=0; j<height; j++)
      this->set(i, j, T());
}

template<class T>
Matrix<T>::Matrix(int width, int height, T values[]) {
  this->width = width;
  this->height = height;

  this->values = new T*[width];
  for(int i=0; i<width; i++)
    this->values(i) = new T[height];

  for(int i=0; i<width; i++)
    for(int j=0; j<height; j++)
      this->set(i, j, values[i][j]);
}

template<class T>
Matrix<T>::Matrix(void* value) {
  for(int i=0; i<((Matrix<T>)value).width; i++) {
    for(int j=0; j<((Matrix<T>)value).height; j++) {
      this->set(i, j, ((Matrix<T>)value).get(i, j));
    }
  }
}

template<class T>
Matrix<T>::~Matrix() {
  for(int i=0; i<width; i++) {
    for(int j=0; j<height; j++) {
      delete &this->values[i][j];
    }
    delete &this->values[i];
  }
}

template<class T>
ostream& Matrix<T>::operator<<(Matrix<T>& m) {
  ostream os;
  os << m.toString();
  return os;
}

template<class T>
Matrix<T>& Matrix<T>::operator<<(ostream& os) {
  os << this->toString();
  return *this;
}

template<class T>
Matrix<T>& Matrix<T>::operator=(Matrix<T>& other) {
  this->width = other.getWidth();
  this->height = other.getHeight();

  this->values = new T*[this->width];
  for(int i=0; i<width; i++)
    this->values[i] = new T(height);
  for(int i=0; i<width; i++)
    for(int j=0; j<height; j++)
      this->set(i, j, other.get(i, j));

  return *this;
}

template<class T>
Matrix<T>& Matrix<T>::operator=(T other[]) {
  int max = this->width * this->height;

  this->values = new T*[this->width];
  for(int i=0; i<width; i++)
    this->values[i] = new T(height);
  int count = 0;
  for(int i=0; i<width; i++)
    for(int j=0; j<height; j++)
      this->set(i, j, other[count++]);

  return *this;
}

template<class T>
Matrix<T>& Matrix<T>::operator+(Matrix<T> other) {
  Matrix<T> * result = new Matrix<T>(this->width, this->height);

  int i, j;
  if(other.getWidth() == this->width && other.getHeight() == this->height) {
    for(i=0; i<this->width; i++) {
      for(j=0; j<this->height; j++) {
        T sum = this->values[i][j] + other.get(i, j);
        result->set(i, j, sum);
      }
    }
  }

  return *result;
}

template<class T>
Matrix<T>& Matrix<T>::operator-(Matrix<T> other) {
  Matrix<T> * result = new Matrix<T>(this->width, this->height);

  int i, j;
  if(other.getWidth() == this->width && other.getHeight() == this->height) {
    for(i=0; i<this->width; i++) {
      for(j=0; j<this->height; j++) {
        T sum = this->values[i][j] - other.get(i, j);
        result->set(i, j, sum);
      }
    }
  }

  return *result;
}

template<class T>
Matrix<T>& Matrix<T>::operator*(Matrix<T> other) {
  int width = this->width;
  int height = other.getHeight();
  Matrix<T> * result = new Matrix<T>(width, height);

  if(this->height == other.getWidth()) {
    for(int i=0; i<width; i++) {
      for(int j=0; j<height; j++) {
        int n = this->height;
        for(int k=0; k<n; k++) {
          result->set(i, j, result->get(i, j) + this->get(i, k)*other.get(k, j));
        }
      }
    }
  }

  return *result;
}

template<class T>
Matrix<T>& Matrix<T>::operator*(int number) {
  Matrix<T> * result = new Matrix<T>(this->width, this->height);

  for(int i=0; i<width; i++)
    for(int j=0; j<height; j++)
      result->values[i][j] = number * this->values[i][j];

  return *result;
}

template<class T>
Matrix<T>& Matrix<T>::operator*(float number) {
  Matrix<T> * result = new Matrix<T>(this->width, this->height);

  for(int i=0; i<width; i++)
    for(int j=0; j<height; j++)
      result->values[i][j] = number * this->values[i][j];

  return *result;
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

template<class T>
void Matrix<T>::print() {
  cout << endl;
  for(int i=0; i<this->width; i++) {
    for(int j=0; j<this->height; j++) {
      cout << this->values[i][j];
      if(j < this->height)
        cout << " ";
    }
    cout << endl;
  }
  cout << endl;
}

template<class T>
string Matrix<T>::toString() {
  string result = "\n";

  for(int i=0; i<this->width; i++) {
    for(int j=0; j<this->height; j++) {
      T value = this->values[i][j];
      ostringstream ss;
      ss << value;
      result = result + ss.str();
      if(j < this->height) {
        result = result + " ";
      }
    }
    result = result + "\n";
  }
  result = result + "\n";

  return result;
}

template<class T>
T * Matrix<T>::toArray() {
  T * result = new T[width*height];

  int count = 0;
  for(int i=0; i<this->width; i++) {
    for(int j=0; j<this->height; j++) {
      result[count++] = values[i][j];
    }
  }

  return result;
}
