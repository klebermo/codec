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

    bool operator==(const HuffmanNode<T> & other) const {
        return value == other.value;
    };

    bool operator!=(const HuffmanNode<T> & other) const {
        return value != other.value;
    };

    bool operator<(const HuffmanNode<T> & other) const {
        return frequency < other.frequency;
    };

    bool operator>(const HuffmanNode<T> & other) const {
        return frequency > other.frequency;
    };

    bool operator<=(const HuffmanNode<T> & other) const {
        return frequency <= other.frequency;
    };

    bool operator>=(const HuffmanNode<T> & other) const {
        return frequency >= other.frequency;
    };

    HuffmanNode<T> operator++() {
        frequency++;
        return *this;
    };

    HuffmanNode<T> operator--() {
        frequency--;
        return *this;
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

    void insert(HuffmanNode<T> * node) {
        //
    };

    std::vector<HuffmanNode<T>> preOrder() {
        std::vector<HuffmanNode<T>> result;
        preOrder(root, result);
        return result;
    };

    void preOrder(HuffmanNode<T> * node, std::vector<HuffmanNode<T>> & result) {
        if (node == nullptr) {
            return;
        }
        result.push_back(*node);
        preOrder(node->getLeft(), result);
        preOrder(node->getRight(), result);
    };

    std::vector<HuffmanNode<T>> inOrder() {
        std::vector<HuffmanNode<T>> result;
        inOrder(root, result);
        return result;
    };

    void inOrder(HuffmanNode<T> * node, std::vector<HuffmanNode<T>> & result) {
        if (node == nullptr) {
            return;
        }
        inOrder(node->getLeft(), result);
        result.push_back(*node);
        inOrder(node->getRight(), result);
    };

    std::vector<HuffmanNode<T>> postOrder() {
        std::vector<HuffmanNode<T>> result;
        postOrder(root, result);
        return result;
    };

    void postOrder(HuffmanNode<T> * node, std::vector<HuffmanNode<T>> & result) {
        if (node == nullptr) {
            return;
        }
        postOrder(node->getLeft(), result);
        postOrder(node->getRight(), result);
        result.push_back(*node);
    };
};

template <class T>
std::map<char,std::vector<bool>> get_huffman_table(std::map<char,std::vector<bool>> * table = std::map<char,std::vector<bool>>(), HuffmanNode<T> * node = nullptr, std::vector<bool> code = std::vector<bool>()) {
    std::map<char,std::vector<bool>> result;

    if(node->getLeft() == nullptr && node->getRight() == nullptr) {
        result.insert({node->getValue(), code});
    } else {
        if(node->getLeft() != nullptr) {
            code.push_back(false);
            result = get_huffman_table(result, node->getLeft(), code);
        }
        if(node->getRight() != nullptr) {
            code.push_back(true);
            result = get_huffman_table(result, node->getRight(), code);
        }
    }

    return result;
}

template <class T>
std::vector<T> huffman_encode(std::vector<T> data, std::map<T,std::vector<bool>> table) {
    std::vector<T> result;
    return result;
}

template <class T>
std::vector<T> huffman_decode(std::vector<T> data, std::map<T,std::vector<bool>> table) {
    std::vector<T> result;
    return result;
}

#endif
