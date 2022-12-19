#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

template <typename T>
class HuffmanNode {
public:
    T value;
    int frequency;
    HuffmanNode<T>* left;
    HuffmanNode<T>* right;

    HuffmanNode(T value, int frequency) : value(value), frequency(frequency), left(nullptr), right(nullptr) {}
};

template <typename T>
class HuffmanTree {
public:
    // Builds a Huffman tree from a frequency table
    static HuffmanNode<T>* build(const std::map<T, int>& frequency_table) {
        //std::priority_queue<HuffmanNode<T>*, std::vector<HuffmanNode<T>*>, std::function<bool(HuffmanNode<T>*, HuffmanNode<T>*)>> queue;
        std::queue<HuffmanNode<T>*> queue;
        for (const auto& [value, frequency] : frequency_table) {
            queue.push(new HuffmanNode<T>(value, frequency));
        }
        while (queue.size() > 1) {
            //HuffmanNode<T>* left = queue.top();
            HuffmanNode<T>* left = queue.front();
            queue.pop();
            //HuffmanNode<T>* right = queue.top();
            HuffmanNode<T>* right = queue.front();
            queue.pop();

            T value;
            int frequency = left->frequency + right->frequency;
            HuffmanNode<T>* node = new HuffmanNode<T>(value, frequency);
            node->left = left;
            node->right = right;

            queue.push(node);
        }
        //return queue.top();
        return queue.front();
    }

    // Traverses a Huffman tree and assigns codes to each value in a frequency table
    static void assignCodes(HuffmanNode<T>* root, std::map<T, std::vector<bool>>& codes, std::vector<bool>& prefix) {
        if (root->left == nullptr && root->right == nullptr) {
            codes[root->value] = prefix;
            return;
        }
        prefix.push_back(false);
        assignCodes(root->left, codes, prefix);
        prefix.pop_back();
        prefix.push_back(true);
        assignCodes(root->right, codes, prefix);
        prefix.pop_back();
    }

    // Compresses data using a Huffman tree and frequency table
    static std::vector<uint8_t> compress(const std::vector<T>& data, const std::map<T, std::vector<bool>>& codes) {
        std::vector<uint8_t> compressed;  // Allocate memory for the compressed data
        uint8_t buffer = 0;
        int bits_left = 8;
        for (const T& value : data) {
            std::vector<bool> code = codes.at(value);
            for (bool bit : code) {
                buffer <<= 1;
                if (bit) {
                    buffer |= 1;
                }
                bits_left--;
                if (bits_left == 0) {
                    compressed.push_back(buffer);
                    buffer = 0;
                    bits_left = 8;
                }
            }
        }
        if (bits_left != 8) {
            buffer <<= bits_left;
            compressed.push_back(buffer);
        }
        return compressed;
    }

    // Decompresses data using a Huffman tree
    static std::vector<T> decompress(const std::vector<uint8_t>& data, HuffmanNode<T>* root) {
        std::vector<T> decompressed;
        HuffmanNode<T>* current = root;
        for (uint8_t byte : data) {
            for (int i = 0; i < 8; i++) {
                bool bit = byte & (1 << (7 - i));
                if (bit) {
                    current = current->right;
                } else {
                    current = current->left;
                }
                if (current->left == nullptr && current->right == nullptr) {
                    decompressed.push_back(current->value);
                    current = root;
                }
            }
        }
        return decompressed;
    }
};

#endif
