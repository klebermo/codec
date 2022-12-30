#ifndef MATRIX_HPP
#define MATRIX_HPP

template<class T>
class Matrix {
private:
    int width;
    int height;
    T ** data;
public:
    Matrix() {
        width = 0;
        height = 0;
        data = nullptr;
    };

    Matrix(int width, int height) {
        this->width = width;
        this->height = height;
        data = new T*[height];
        for (int i = 0; i < height; i++) {
            data[i] = new T[width];
        }
    };

    Matrix(int width, int height, T ** data) {
        this->width = width;
        this->height = height;
        this->data = data;
    };

    Matrix(std::vector<std::vector<T>> data) {
        this->width = data[0].size();
        this->height = data.size();
        this->data = new T*[height];
        for (int i = 0; i < height; i++) {
            this->data[i] = new T[width];
            for (int j = 0; j < width; j++) {
                this->data[i][j] = data[i][j];
            }
        }
    };

    T * operator[](int index) {
        return data[index];
    };

    int getWidth() {
        return width;
    };

    int getHeight() {
        return height;
    };
};

#endif
