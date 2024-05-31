#include "Huffman.h"
#include <iostream>

int main() 
{
    std::string word;
    std::cout << "Please input a word: ";
    std::getline(std::cin, word);
    std::cout << std::endl;

    Huffman huffman(word);
    std::string encodedText = huffman.encode();
    std::cout << "Encoded text: " << encodedText << std::endl;
    huffman.printCodes();
    std::string originalText = huffman.decode(encodedText);
    std::cout << "Decoded text: " << originalText << std::endl;
    return 0;
}
