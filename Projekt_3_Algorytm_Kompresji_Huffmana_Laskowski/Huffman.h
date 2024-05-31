#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "Node.h"
#include <queue>
#include <unordered_map>
#include <string>
#include <vector>

class Huffman 
{
private:
    std::shared_ptr<Node> root;
    std::string text;
    std::unordered_map<char, int> charFrequencies;
    std::unordered_map<char, std::string> huffmanCodes;

    void fillCharFrequenciesMap();
    void generateHuffmanCodes(std::shared_ptr<Node> node, const std::string& code);
    std::string getEncodedText() const;

public:
    Huffman(const std::string& text);
    std::string encode();
    std::string decode(const std::string& encodedText) const;
    void printCodes() const;
};

#endif 
