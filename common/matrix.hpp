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

    Matrix(std::vector<unsigned char> data, int rows, int cols) {
        this->rows = rows;
        this->cols = cols;
        matrix = new T*[rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new T[cols];
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = data[i * cols + j];
            }
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

    bool empty() {
        return rows == 0 || cols == 0;
    };

    std::vector<T> to_vector() {
        std::vector<T> result;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.push_back(matrix[i][j]);
            }
        }
        return result;
    };

    T* operator[](int row) {
        return matrix[row];
    };

    T& operator=(const T& other) {
        if (this != &other) {
            for (int i = 0; i < rows; i++) {
                delete[] matrix[i];
            }
            delete[] matrix;
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
        return *this;
    };

    T& operator=(T&& other) {
        if (this != &other) {
            for (int i = 0; i < rows; i++) {
                delete[] matrix[i];
            }
            delete[] matrix;
            rows = other.rows;
            cols = other.cols;
            matrix = other.matrix;
            other.rows = 0;
            other.cols = 0;
            other.matrix = nullptr;
        }
        return *this;
    };

    T& operator=(std::initializer_list<std::initializer_list<T>> list) {
        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
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
        return *this;
    };

    T& operator+=(const T& other) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] += other.matrix[i][j];
            }
        }
        return *this;
    };

    T& operator-(const T& other) {
        T result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
            }
        }
        return result;
    };

    T& operator*(const T& other) {
        T result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                result.matrix[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
                }
            }
        }
        return result;
    };

    T& operator*(int scalar) {
        T result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.matrix[i][j] = matrix[i][j] * scalar;
            }
        }
        return result;
    };

    T& operator/(const T& other) {
        T result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.matrix[i][j] = matrix[i][j] / other.matrix[i][j];
            }
        }
        return result;
    };

    T& operator/(int scalar) {
        T result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.matrix[i][j] = matrix[i][j] / scalar;
            }
        }
        return result;
    };

    T& operator++() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j]++;
            }
        }
        return *this;
    };

    T& operator--() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j]--;
            }
        }
        return *this;
    };
};

#endif
