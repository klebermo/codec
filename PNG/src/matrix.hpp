#ifndef MATRIX_HPP
#define MATRIX_HPP

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