#include "Huffman.h"
#include <iostream>
#include <sstream>

void Huffman::fillCharFrequenciesMap() 
{
    for (char character : text) 
    {
        charFrequencies[character]++;
    }
}

void Huffman::generateHuffmanCodes(std::shared_ptr<Node> node, const std::string& code) 
{
    if (!node->leftNode && !node->rightNode) 
    {
        auto leaf = std::dynamic_pointer_cast<Leaf>(node);
        huffmanCodes[leaf->character] = code;
        return;
    }
    generateHuffmanCodes(node->leftNode, code + "0");
    generateHuffmanCodes(node->rightNode, code + "1");
}

std::string Huffman::getEncodedText() const 
{
    std::stringstream ss;
    for (char character : text) 
    {
        ss << huffmanCodes.at(character);
    }
    return ss.str();
}

Huffman::Huffman(const std::string& text) : text(text) 
{
    fillCharFrequenciesMap();
}

std::string Huffman::encode()
{
    auto compare = [](std::shared_ptr<Node> a, std::shared_ptr<Node> b) 
        {
        return *a > *b;
        };
    std::priority_queue<std::shared_ptr<Node>, std::vector<std::shared_ptr<Node>>, decltype(compare)> queue(compare);

    for (const auto& pair : charFrequencies) 
    {
        queue.push(std::make_shared<Leaf>(pair.first, pair.second));
    }

    while (queue.size() > 1) 
    {
        auto left = queue.top(); queue.pop();
        auto right = queue.top(); queue.pop();
        auto node = std::make_shared<Node>(left->frequency + right->frequency, left, right);
        queue.push(node);
    }

    root = queue.top();
    generateHuffmanCodes(root, "");

    return getEncodedText();
}

std::string Huffman::decode(const std::string& encodedText) const 
{
    std::stringstream ss;
    auto current = root;
    for (char bit : encodedText) 
    {
        current = (bit == '0') ? current->leftNode : current->rightNode;
        if (!current->leftNode && !current->rightNode) 
        {
            auto leaf = std::dynamic_pointer_cast<Leaf>(current);
            ss << leaf->character;
            current = root;
        }
    }
    return ss.str();
}

void Huffman::printCodes() const 
{
    for (const auto& pair : huffmanCodes) 
    {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}
