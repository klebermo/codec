#ifndef AVI_HPP
#define AVI_HPP

struct Pixel {
  float r, g, b;
};
typedef struct Pixel Pixel;

template<class T> class Matrix {};

class AVI {
protected:
    std::vector<<Matrix<Pixel>> pixels;
public:
    void read(std::string filename);
    void write(std::string filename);

    int getFrameCount();
    int getFrameRate();
    int getWidth();
    int getHeight();

  std::vector<float> toArray();
};

#endif
