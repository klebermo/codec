#ifndef COM_H
#define COM_H

class COM {
private:
    unsigned char * data;
public:
    COM() {
        data = nullptr;
    }

    COM(unsigned char * data) {
        this->data = data;
    }

    ~COM() {
        delete[] data;
    }

    COM& operator=(unsigned char * data) {
        this->data = data;
        return *this;
    }

    unsigned char * getData() {
        return data;
    }
};

#endif
