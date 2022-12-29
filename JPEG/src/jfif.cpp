#include "jfif.hpp"

bool Jfif::encode() {
    if(pixels.empty())
        return false;
    else {
        int w = pixels.getWidth(), h = pixels.getHeight();
        std::vector<RgbPixel> pixels_vector = pixels.toVector();

        //The representation of the colors in the image is converted from RGB to YCBCR
        std::vector<YCbCrPixel> ycbcr_pixels_vector;
        for(std::vector<RgbPixel>::iterator it = pixels_vector.begin(); it != pixels_vector.end(); ++it) {
            ycbcr_pixels_vector.push_back(RgbToYCbCr(*it));
        }

        //The resolution of the chroma data is reduced, usually by a factor of 2 or 3
        ycbcr_pixels_vector = reduceChromaResolution(ycbcr_pixels_vector, 2);

        //The image is split into blocks of 8×8 pixels, and for each block, each of the Y, CB, and CR data undergoes the discrete cosine transform (DCT)
        ycbcr_pixels_vector = calculateDCT(ycbcr_pixels_vector, w, h);

        //The amplitudes of the frequency components are quantized
        std::vector<std::vector<int>> quantization_matrix = generateQuantizationMatrix(1);
        ycbcr_pixels_vector = quantizeImage(ycbcr_pixels_vector, w, h, quantization_matrix);

        //The resulting data for all 8×8 blocks is further compressed with a lossless algorithm, a variant of Huffman encoding
        std::map<unsigned char, std::vector<bool>> huffman_table = std::map<unsigned char, std::vector<bool>>();
        std::vector<unsigned char> pixel_vector;
        for(std::vector<YCbCrPixel>::iterator it = ycbcr_pixels_vector.begin(); it != ycbcr_pixels_vector.end(); ++it) {
            pixel_vector.push_back(it->y);
            pixel_vector.push_back(it->cb);
            pixel_vector.push_back(it->cr);
        }
        std::vector<unsigned char> compressed_data = huffman_encode<unsigned char>(pixel_vector, huffman_table);

        return true;
    }
}

bool Jfif::decode() {
    if(!pixels.empty()) {
        return false;
    } else {
        int h = (sof0.height[1] - '0') + 10*(sof0.height[0]-'0'), w = (sof0.width[1] - '0') + 10*(sof0.width[0]-'0');

        //The compressed data is decompressed with a lossless algorithm, a variant of Huffman encoding
        std::map<unsigned char, std::vector<bool>> huffman_table = std::map<unsigned char, std::vector<bool>>();
        std::vector<unsigned char> pixels_vector = huffman_decode<unsigned char>(raw_data, huffman_table);
        std::vector<YCbCrPixel> ycbcr_pixels_vector;
        for(std::vector<unsigned char>::iterator it = pixels_vector.begin(); it != pixels_vector.end(); ++it) {
            YCbCrPixel p;
            p.y = *it;
            ++it;
            p.cb = *it;
            ++it;
            p.cr = *it;
            ycbcr_pixels_vector.push_back(p);
        }

        //The amplitudes of the frequency components are dequantized
        std::vector<std::vector<int>> quantization_matrix = generateQuantizationMatrix(1);
        ycbcr_pixels_vector = dequantizeImage(ycbcr_pixels_vector, w, h, quantization_matrix);

        //The DCT is inverted
        ycbcr_pixels_vector = reverseDCT(ycbcr_pixels_vector, w, h);

        //The resolution of the chroma data is increased, usually by a factor of 2 or 3
        ycbcr_pixels_vector = increaseChromaResolution(ycbcr_pixels_vector, 2);

        //The representation of the colors in the image is converted from YCBCR to RGB
        std::vector<RgbPixel> rgb_pixels_vector;
        for(std::vector<YCbCrPixel>::iterator it = ycbcr_pixels_vector.begin(); it != ycbcr_pixels_vector.end(); ++it) {
            rgb_pixels_vector.push_back(YCbCrToRgb(*it));
        }

        pixels = Matrix<RgbPixel>(rgb_pixels_vector, w, h);
        return true;
    }
}

bool Jfif::readFile(std::string filename) {
    std::ifstream file(filename, std::ios::binary);

    if(!file.is_open()) {
        return false;
    }

    unsigned char buffer[2];
    while(file.read((char*)buffer, 2)) {
        if(buffer[0] == 0xFF && buffer[1] == 0xD8) {
            file.seekg(-2, std::ios::cur);
            file.read((char*)&soi, sizeof(SOI));
        }

        if(buffer[0] == 0xFF && buffer[1] == 0xC0) {
            file.seekg(-2, std::ios::cur);
            file.read((char*)&sof0, sizeof(SOF0));
        }

        if(buffer[0] == 0xFF && buffer[1] == 0xC4) {
            file.seekg(-2, std::ios::cur);
            file.read((char*)&dht, sizeof(DHT));
        }

        if(buffer[0] == 0xFF && buffer[1] == 0xDB) {
            file.seekg(-2, std::ios::cur);
            file.read((char*)&dqt, sizeof(DQT));
        }

        if(buffer[0] == 0xFF && buffer[1] == 0xDA) {
            file.seekg(-2, std::ios::cur);
            file.read((char*)&sos, sizeof(SOS));

            // Read the compressed data
            unsigned char marker[2];
            while(file.read((char*)marker, 2)) {
                if(marker[0] == 0xFF && marker[1] == 0xD9) {
                    file.seekg(-2, std::ios::cur);
                    file.read((char*)&eoi, sizeof(EOI));
                    break;
                } else {
                    //compressed_data.push_back(marker[0]);
                    //compressed_data.push_back(marker[1]);
                }
            }
        }

        if(buffer[0] == 0xFF && buffer[1] == 0xE0) {
            file.seekg(2, std::ios::cur);
            char id[5];
            file.read(id, 5);

            if(id[0] == 'J' && id[1] == 'F' && id[2] == 'I' && id[3] == 'F' && id[4] == '\0') {
                file.seekg(-7, std::ios::cur);
                file.read((char*)&app0, 18);
                int n = static_cast<int>(app0.x_thumbnail) * static_cast<int>(app0.y_thumbnail);
                for(int i=0; i<3*n; i++) {
                    unsigned char c;
                    file.read((char*)&c, 1);
                    app0.thumbnail.push_back(c);
                }
            }

            if(id[0] == 'J' && id[1] == 'F' && id[2] == 'X' && id[3] == 'X' && id[4] == '\0') {
                file.seekg(-7, std::ios::cur);
                file.read((char*)&app1, 10);
                int length = 10*(app0.length[0] - '0') + (app0.length[1] - '0');
                int n = length - 8;
                if(app1.extension_code == 0x10) {
                    for(int i=0; i<n; i++) {
                        unsigned char c;
                        file.read((char*)&c, 1);
                        app1.thumbnail.push_back(c);
                    }
                }
                if(app1.extension_code == 0x11) {
                    for(int i=0; i<n; i++) {
                        unsigned char c;
                        file.read((char*)&c, 1);
                        app1.thumbnail.push_back(c);
                    }
                }
                if(app1.extension_code == 0x13) {
                    for(int i=0; i<n; i++) {
                        unsigned char c;
                        file.read((char*)&c, 1);
                        app1.thumbnail.push_back(c);
                    }
                }
            }
        }

        if(buffer[0] == 0xFF && buffer[1] == 0xFE) {
            file.seekg(-2, std::ios::cur);
            file.read((char*)&com, sizeof(COM));
        }
    }

    return decode();
}

bool Jfif::writeFile(std::string filename, Matrix<RgbPixel> pixels) {
    std::ofstream file(filename, std::ios::binary);

    if(!file.is_open()) {
        return false;
    }

    if(pixels.empty()) {
        if(encode()) {
            file.write((char*)&soi, sizeof(SOI));
            file.write((char*)&sof0, sizeof(SOF0));
            file.write((char*)&dqt, sizeof(DQT));
            file.write((char*)&dht, sizeof(DHT));
            file.write((char*)&app0, sizeof(JFIF_APP0));
            file.write((char*)&app1, sizeof(JFXX_APP0));
            file.write((char*)&com, sizeof(COM));
            file.write((char*)&sos, sizeof(SOS));
            file.write((char*)&eoi, sizeof(EOI));
            return true;
        }
    }

    return false;
}

int Jfif::getWidth() {
    return pixels.getWidth();
}

int Jfif::getHeight() {
    return pixels.getHeight();
}
