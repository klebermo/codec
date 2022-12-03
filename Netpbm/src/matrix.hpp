#ifndef LIB_MATRIX_H
#define LIB_MATRIX_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <bitset>
#include <cstring>
#include <cmath>

template <class T>
class Matrix {
private:
    int height;
    int width;
    T ** values;
public:
    Matrix(int height, int width) {
        values = new T*[height];
        for(int i=0; i<height; i++)
            values[i] = new T[width];
        this->height = height;
        this->width = width;
    }

    Matrix(const Matrix<T> &other) {
        height = other.height;
        width = other.width;
        values = new T*[height];
        for(int i=0; i<height; i++)
            values[i] = new T[width];
        for(int i=0; i<height; i++)
            for(int j=0; j<width; j++)
                values[i][j] = other.values[i][j];
    }

    ~Matrix() {
        for(int i=0; i<height; i++)
            delete[] values[i];
        delete[] values;
    }

    T * operator[](int index) {
        return values[index];
    }
};

#endif
