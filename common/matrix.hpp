#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <initializer_list>

template<class T>
class Matrix {
private:
  T ** matrix;
  int rows;
  int cols;
public:
    Matrix() {
        rows = 0;
        cols = 0;
        matrix = nullptr;
    };

    Matrix(int rows, int cols) {
        this->rows = rows;
        this->cols = cols;
        matrix = new T*[rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new T[cols];
        }
    };

    Matrix(const Matrix& other) {
        rows = other.rows;
        cols = other.cols;
        matrix = new T*[rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new T[cols];
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }

    Matrix(Matrix&& other) {
        rows = other.rows;
        cols = other.cols;
        matrix = other.matrix;
        other.rows = 0;
        other.cols = 0;
        other.matrix = nullptr;
    }

    Matrix(std::initializer_list<std::initializer_list<T>> list) {
        rows = list.size();
        cols = list.begin()->size();
        matrix = new T*[rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new T[cols];
        }
        int i = 0;
        for (auto row : list) {
            int j = 0;
            for (auto col : row) {
                matrix[i][j] = col;
                j++;
            }
            i++;
        }
    }

    Matrix(int rows, int cols, T ** values) {
        this->rows = rows;
        this->cols = cols;
        matrix = new T*[rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new T[cols];
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = values[i][j];
            }
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    };

    T get(int row, int col) {
        return matrix[row][col];
    };

    void set(int row, int col, T value) {
        matrix[row][col] = value;
    };

    int get_rows() {
        return rows;
    };

    int get_cols() {
        return cols;
    };

    T* operator[](int row) {
        return matrix[row];
    };
};

#endif
