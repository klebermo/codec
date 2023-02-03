#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

#include <list>
#include <map>
#include <vector>

template<class T>
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

    HuffmanNode(HuffmanNode * left, HuffmanNode * right) {
        this->left = left;
        this->right = right;
        this->frequency = left->frequency + right->frequency;
    };

    ~HuffmanNode() {
        if (left != nullptr) {
            delete left;
        }
        if (right != nullptr) {
            delete right;
        }
    };

    T getValue() {
        return value;
    };

    int getFrequency() {
        return frequency;
    };

    HuffmanNode * getLeft() {
        return left;
    };

    HuffmanNode * getRight() {
        return right;
    };

    bool isLeaf() {
        return left == nullptr && right == nullptr;
    };

    bool operator<(const HuffmanNode& other) const {
        return frequency < other.frequency;
    };

    bool operator>(const HuffmanNode& other) const {
        return frequency > other.frequency;
    };

    bool operator<=(const HuffmanNode& other) const {
        return frequency <= other.frequency;
    };

    bool operator>=(const HuffmanNode& other) const {
        return frequency >= other.frequency;
    };

    bool operator==(const HuffmanNode& other) const {
        return value == other.value;
    };
};

template<class T>
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

    ~HuffmanTree() {
        if (root != nullptr) {
            delete root;
        }
    };

    HuffmanNode<T> * getRoot() {
        return root;
    };

    void setRoot(HuffmanNode<T> * root) {
        this->root = root;
    };

    void insert(T value, int frequency) {
        HuffmanNode<T> * node = new HuffmanNode<T>(value, frequency);
        if (root == nullptr) {
            root = node;
        } else {
            HuffmanNode<T> * current = root;
            HuffmanNode<T> * parent = nullptr;
            while (true) {
                parent = current;
                if (value == current->getValue()) {
                    current->getFrequency()++;
                    return;
                }

                if (node->getFrequency() < current->getFrequency()) {
                    current = current->getLeft();
                } else {
                    current = current->getRight();
                }

                if(current == nullptr) {
                    break;
                }
            }

            if (frequency < parent->getFrequency()) {
                parent->setLeft(node);
            } else {
                parent->setRight(node);
            }
        }
    };

    std::list<HuffmanNode<T>> preOrder() {
        std::list<HuffmanNode<T>> list;
        preOrder(root, list);
        return list;
    };

    std::list<HuffmanNode<T>> preOrder(HuffmanNode<T> * node, std::list<HuffmanNode<T>> & list) {
        if (node != nullptr) {
            list.push_back(node);
            preOrder(node->getLeft(), list);
            preOrder(node->getRight(), list);
        }
    };

    std::list<HuffmanNode<T>> inOrder() {
        std::list<HuffmanNode<T>> list;
        inOrder(root, list);
        return list;
    };

    std::list<HuffmanNode<T>> inOrder(HuffmanNode<T> * node, std::list<HuffmanNode<T>> & list) {
        if (node != nullptr) {
            inOrder(node->getLeft(), list);
            list.push_back(node);
            inOrder(node->getRight(), list);
        }
    };

    std::list<HuffmanNode<T>> postOrder() {
        std::list<HuffmanNode<T>> list;
        postOrder(root, list);
        return list;
    };

    std::list<HuffmanNode<T>> postOrder(HuffmanNode<T> * node, std::list<HuffmanNode<T>> & list) {
        if (node != nullptr) {
            postOrder(node->getLeft(), list);
            postOrder(node->getRight(), list);
            list.push_back(node);
        }
    };

    std::map<T, std::vector<bool>> getCodes() {
        std::map<T, std::vector<bool>> codes;
        getCodes(root, codes, std::vector<bool>());
        return codes;
    };

    void getCodes(HuffmanNode<T> * node, std::map<T, std::vector<bool>> & codes, std::vector<bool> code) {
        if (node.left != nullptr && node.right != nullptr) {
            codes[node.value] = code;
        } else {
            if(node.left != nullptr) {
                code.push_back(false);
                getCodes(node.left, codes, code);
            }
            if(node.right != nullptr) {
                code.push_back(true);
                getCodes(node.right, codes, code);
            }
        }
    };
};

#endif
