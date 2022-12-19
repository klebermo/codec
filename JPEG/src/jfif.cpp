#include "jfif.hpp"

bool Jfif::encode() {
    if(pixels.empty())
        return false;
    else {
        int h = pixels.get_rows();
        int w = pixels.get_cols();
        std::vector<YCbCrPixel> ycbcr_pixels;
        for(int i = 0; i < pixels.get_cols(); i++) {
            for(int j=0; j < pixels.get_rows(); j++) {
                RgbPixel rgb = pixels[i][j];
                YCbCrPixel ycbcr = RgbToYCbCr(rgb);
                ycbcr_pixels.push_back(ycbcr);
            }
        }

        ycbcr_pixels = reduceChromaResolution(ycbcr_pixels, 2);
        ycbcr_pixels = calculateDCT(ycbcr_pixels, h, w);
        ycbcr_pixels = quantize(ycbcr_pixels, h, w, generateQuantizationMatrix(100));
        
        std::vector<uint8_t> image = compressQuantizedImage(ycbcr_pixels);
        for(int i = 0; i < image.size(); i++) {
            compressed_data.push_back(image[i]);
        }

        return true;
    }
}

bool Jfif::decode() {
    if(compressed_data.empty())
        return false;
    else {
        int h = getHeight();
        int w = getWidth();
        std::vector<unsigned char> image = decompressQuantizedImage(compressed_data, h, w);
        
        //Matrix<YCbCrPixel> ycbcr_pixels(image, h, w);
        std::vector<YCbCrPixel> ycbcr_pixels = reverseDCT(ycbcr_pixels);
        ycbcr_pixels = reverseChromaResolutionReduction(ycbcr_pixels, 2);

        //pixels = Matrix<RgbPixel>(h, w);
        int index = 0;
        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                YCbCrPixel ycbcr = ycbcr_pixels[index++];
                RgbPixel rgb = YCbCrToRgb(ycbcr);
                pixels[i][j] = rgb;
            }
        }

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

        if(buffer[0] == 0xFF && buffer[1] == 0xDD) {
            file.seekg(-2, std::ios::cur);
            file.read((char*)&dri, sizeof(DRI));
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
                    compressed_data.push_back(marker[0]);
                    compressed_data.push_back(marker[1]);
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
            }

            if(id[0] == 'J' && id[1] == 'F' && id[2] == 'X' && id[3] == 'X' && id[4] == '\0') {
                file.seekg(-7, std::ios::cur);
                file.read((char*)&app1, 10);
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

    if(compressed_data.size() == 0) {
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
            file.write((char*)&dri, sizeof(DRI));
            file.write((char*)&sos, sizeof(SOS));
            file.write((char*)compressed_data.data(), compressed_data.size()*sizeof(unsigned char));
            file.write((char*)&eoi, sizeof(EOI));
        }
    }

    return false;
}

int Jfif::getWidth() {
    int result = (sof0.width[0] - '0') + (sof0.width[1] - '0');
    return result;
}

int Jfif::getHeight() {
    int result = (sof0.height[0] - '0') + (sof0.height[1] - '0');
    return result;
}
