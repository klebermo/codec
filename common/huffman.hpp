#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

template <class T>
class HuffmanNode {
private:
    T value;
    int frequency;
    HuffmanNode * left;
    HuffmanNode * right;
public:
    HuffmanNode(T value, int frequency) {
        this->value = value;
        this->frequency = frequency;
        left = nullptr;
        right = nullptr;
    };

    HuffmanNode(HuffmanNode<T> * left, HuffmanNode<T> * right) {
        this->frequency = left->getFrequency() + right->getFrequency();
        this->left = left;
        this->right = right;
    };

    T getValue() {
        return value;
    };

    void setValue(T value) {
        this->value = value;
    };

    int getFrequency() {
        return frequency;
    };

    void setFrequency(int frequency) {
        this->frequency = frequency;
    };

    HuffmanNode * getLeft() {
        return left;
    };

    HuffmanNode * getRight() {
        return right;
    };
};

template <class T>
class HuffmanTree {
private:
    HuffmanNode<T> * root;
public:
    HuffmanTree() {
        root = nullptr;
    };
    
    HuffmanTree(HuffmanNode<T> * root) {
        this->root = root;
    };

    HuffmanNode<T> * getRoot() {
        return root;
    };

    void insert(T value, int frequency) {
        HuffmanNode<T> * node = new HuffmanNode<T>(value, frequency);
        if (root == nullptr) {
            root = node;
        } else {
            HuffmanNode<T> * current = root;
            while (current->getLeft() != nullptr && current->getRight() != nullptr) {
                if (current->getLeft()->getFrequency() < current->getRight()->getFrequency()) {
                    current = current->getLeft();
                } else {
                    current = current->getRight();
                }
                if(current->getValue() == value) {
                    current->setFrequency(current->getFrequency() + frequency);
                    return;
                }
            }
            if (current->getLeft() == nullptr) {
                current->setLeft(node);
            } else {
                current->setRight(node);
            }
        }
    };

    std::map<T, std::vector<bool>> getCodes(HuffmanNode<T> * node = nullptr, std::vector<bool> codes = std::vector<bool>()) {
        std::map<T, std::vector<bool>> table;

        if(node == nullptr) {
            node = root;
        }

        if(node->getLeft() == nullptr && node->getRight() == nullptr) {
            table.insert({node->getValue(), codes});
        } else {
            if(node->getLeft() != nullptr) {
                codes.push_back(false);
                getCodes(node->getLeft(), codes);
            }
            if(node->getRight() != nullptr) {
                codes.push_back(true);
                getCodes(node->getRight(), codes);
            }
        }

        return table;
    };

    std::vector<T> compress(std::vector<T> raw_data) {
        std::vector<T> result;
        //
        return result;
    }

    std::vector<T> decompress(std::vector<T> compressed_data) {
        std::vector<T> result;
        //
        return result;
    }
};

#endif
