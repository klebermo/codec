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
    Matrix(int h, int w) {
        height = h;
        width = w;

        values = new T*[h];
        for(int i=0; i<h; i++)
            values[i] = new T[w];
    }

    Matrix(const Matrix<T> &other) {
        height = other.height;
        width = other.width;

        values = new T*[other.height];
        for(int i=0; i<other.height; i++)
            values[i] = new T[other.width];

        for(int i=0; i<other.height; i++)
            for(int j=0; j<other.width; j++)
                values[i][j] = other.values[i][j];
    }

    ~Matrix() {
        for(int i=0; i<height; i++) delete[] values[i];
        delete[] values;
    }

    T* operator[](int index) {
        return values[index];
    }

    Matrix<T>& operator=(const Matrix<T> &other) {
        if(this == &other)
            return *this;
        
        if(height != other.height || width != other.width) {
            for(int i=0; i<height; i++)
                delete[] values[i];
            delete[] values;

            height = other.height;
            width = other.width;

            values = new T*[other.height];
            for(int i=0; i<other.height; i++)
                values[i] = new T[other.width];
        }

        for(int i=0; i<height; i++)
            for(int j=0; j<width; j++)
                values[i][j] = other.values[i][j];
        
        return *this;
    }
};

#endif
