#ifndef MATRIX_HPP
#define MATRIX_HPP

template <class T>
class Matrix {
private:
    T ** data;
    int width;
    int height;
public:
    Matrix() {
        width = 0;
        height = 0;
        data = nullptr;
    };
    
    Matrix(int width, int height) {
        this->width = width;
        this->height = height;
        data = new T*[width];
        for (int i = 0; i < width; i++) {
            data[i] = new T[height];
        }
    };

    Matrix(std::vector<T> data, int width, int height) {
        this->width = width;
        this->height = height;
        this->data = new T*[width];
        for (int i = 0; i < width; i++) {
            this->data[i] = new T[height];
        }
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                this->data[i][j] = data[i * height + j];
            }
        }
    };

    ~Matrix() {
        for (int i = 0; i < width; i++) {
            delete[] data[i];
        }
        delete[] data;
    };

    T get(int x, int y) {
        return data[x][y];
    };

    void set(int x, int y, T value) {
        data[x][y] = value;
    };

    int getWidth() {
        return width;
    };

    int getHeight() {
        return height;
    };

    T ** getData() {
        return data;
    };

    void setData(T ** data) {
        this->data = data;
    };

    std::vector<T> toVector() {
        std::vector<T> result;
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                result.push_back(data[i][j]);
            }
        }
        return result;
    };

    bool empty() {
        return data == nullptr;
    };

    T * operator[](int i) {
        return data[i];
    };
};

#endif
