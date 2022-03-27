#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;

#include <string>
using namespace std;

#include <sstream>
using namespace std;

#include <cmath>
using namespace std;

template<class T>
class Matrix
{
protected:
    int width;
    int height;
    T ** values;
public:
    Matrix(int width, int height);
    Matrix(int width, int height, T values[]);
    Matrix(void* value);
    ~Matrix();

    ostream& operator<<(Matrix<T>& m);
    Matrix<T>& operator<<(ostream& os);

    Matrix<T>& operator=(Matrix<T>& other);
    Matrix<T>& operator=(T other[]);
    Matrix<T>& operator+(Matrix<T> other);
    Matrix<T>& operator-(Matrix<T> other);
    Matrix<T>& operator*(Matrix<T> other);
    Matrix<T>& operator*(int number);
    Matrix<T>& operator*(float number);

    T get(int i, int j);
    void set(int i, int j, T value);
    int getWidth();
    int getHeight();

    void print();
    string toString();
    T * toArray();
};

#include "matrix.cpp"

#endif //MATRIX_H
