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
#include <algorithm>

template <class T>
class Matrix {
private:
    size_t height;
    size_t width;
    T ** values;
public:
    Matrix() {
        height = width = 0;
        values = nullptr;
    }

    Matrix(int h, int w) : height(h), width(w), values(new T*[height]) {
        for (size_t i {}; i < height; ++i) {
            values[i] = new T[width];
        }
    }

    Matrix(const Matrix<T> &other) : Matrix(other.height, other.width) {
        for(size_t ht {}; ht < height; ++ht)
            std::copy_n(other.values[ht], width, values[ht]);
    }

    Matrix(Matrix &&other) {
        swap(other);
    }

    Matrix &operator=(Matrix other) {
        swap(other);
        return *this;
    }

    size_t getHeight() const {
        return height;
    }

    size_t getWidth() const {
        return width;
    }

    ~Matrix() {
        clear();
    }

    void swap(Matrix &other) {
        std::swap(height, other.height);
        std::swap(width, other.width);
        std::swap(values, other.values);
    }

    void clear() {
        for (size_t i {}; i < height; ++i)
            delete[] values[i];
        delete[] values;
        height = width = 0;
        values = nullptr;
    }

    void resize(size_t h, size_t w) {
        clear();
        height = h;
        width = w;
        values = new T*[height];
        for (size_t i {}; i < height; ++i) {
            values[i] = new T[width];
        }
    }

    T* operator[](size_t i) {
        return values[i];
    }

    const T* operator[](size_t i) const {
        return values[i];
    }
};

#endif
