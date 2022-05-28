#ifndef Node_h
#define Node_h
// Integer List Item

class Node
{
    public:
        int data;
        Node* prev;
        Node* next;

        Node();
        Node(int data_);
};

Node::Node()
{
    prev = nullptr;
    next = nullptr;
}

Node::Node(int data_)
{
    data = data_;
    prev = nullptr;
    next = nullptr;
}

#endif