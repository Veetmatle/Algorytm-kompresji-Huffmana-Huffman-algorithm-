#ifndef NODE_H
#define NODE_H

#include <memory>

class Node 
{
public:
    int frequency;

    //inteligentne wskaüniki
    std::shared_ptr<Node> leftNode;
    std::shared_ptr<Node> rightNode;

    Node(int frequency, std::shared_ptr<Node> leftNode = nullptr, std::shared_ptr<Node> rightNode = nullptr)
        : frequency(frequency), leftNode(leftNode), rightNode(rightNode) {}

    virtual ~Node() = default; 

    bool operator>(const Node& other) const 
    {
        return frequency > other.frequency;
    }
};

class Leaf : public Node 
{
public:
    char character;

    Leaf(char character, int frequency)
        : Node(frequency), character(character) {}
};

#endif 
