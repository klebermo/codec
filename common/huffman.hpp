#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

template<class T>
class HuffmanNode {
private:
    T value;
    int frequency;
    HuffmanNode<T> * left;
    HuffmanNode<T> * right;
public:
    HuffmanNode(T value, int frequency) {
        this->value = value;
        this->frequency = frequency;
        left = nullptr;
        right = nullptr;
    };

    HuffmanNode(HuffmanNode<T> * left, HuffmanNode<T> * right) {
        this->left = left;
        this->right = right;
        this->frequency = left->frequency + right->frequency;
    };

    T getValue() {
        return value;
    };

    int getFrequency() {
        return frequency;
    };

    HuffmanNode<T> * getLeft() {
        return left;
    };

    HuffmanNode<T> * getRight() {
        return right;
    };
};

template<class T>
class HuffmanTree {
private:
    HuffmanNode<T> * root;
public:
    HuffmanTree(HuffmanNode<T> * root) {
        this->root = root;
    };

    HuffmanNode<T> * getRoot() {
        return root;
    };

    std::map<T, std::vector<bool>> get_huffman_table() {
        std::map<T, std::vector<bool>> table;
        return table;
    }
};

#endif
