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

    bool operator==(HuffmanNode<T> & other) {
        return value == other.value;
    };

    bool operator!=(HuffmanNode<T> & other) {
        return value != other.value;
    };

    bool operator<(HuffmanNode<T> & other) {
        return frequency < other.frequency;
    };

    bool operator>(HuffmanNode<T> & other) {
        return frequency > other.frequency;
    };

    bool operator<=(HuffmanNode<T> & other) {
        return frequency <= other.frequency;
    };

    bool operator>=(HuffmanNode<T> & other) {
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

    HuffmanNode<T> * getRoot() {
        return root;
    };

    void setRoot(HuffmanNode<T> * root) {
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

template <typename T>
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

template <typename T>
std::vector<T> huffman_encode(std::vector<T> data, std::map<T,std::vector<bool>>& table) {
    std::vector<T> result;

    std::list<HuffmanNode<T>> priorityQueue;
    for(auto it = data.begin(); it != data.end(); it++) {
        HuffmanNode<T> node(*it, 1);

        bool existe = false;
        for(auto pos = priorityQueue.begin(); pos != priorityQueue.end(); pos++) {
            if(*pos == node) {
                *pos++;
                existe = true;
                break;
            }
        }

        if(!existe)
            priorityQueue.push_back(node);
    }
    priorityQueue.sort();

    while(priorityQueue.size() > 1) {
        HuffmanNode<T> * left = new HuffmanNode<T>(priorityQueue.front());
        priorityQueue.pop_front();
        HuffmanNode<T> * right = new HuffmanNode<T>(priorityQueue.front());
        priorityQueue.pop_front();

        HuffmanNode<T> * node = new HuffmanNode<T>(left, right);
        node->setValue(' ');
        node->setFrequency(left->getFrequency() + right->getFrequency());
        priorityQueue.push_back(*node);
    }

    for(auto it = data.begin(); it != data.end(); it++) {
        std::vector<bool> code = table.at(*it);
        for(auto it2 = code.begin(); it2 != code.end(); it2++) {
            result.push_back(*it2 ? 0x1 : 0x0);
        }
    }

    return result;
}

template <typename T>
std::vector<T> huffman_decode(std::vector<T> data, std::map<T,std::vector<bool>> table) {
    std::vector<T> result;

    for(auto it = data.begin(); it != data.end(); it++) {
        std::vector<bool> code;
        while(it != data.end() && *it != 0x0 && *it != 0x1) {
            code.push_back(*it);
            it++;
        }
        for(auto it2 = table.begin(); it2 != table.end(); it2++) {
            if(it2->second == code) {
                result.push_back(it2->first);
                break;
            }
        }
    }

    return result;
}

#endif
