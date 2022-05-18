// Integer Linked List Item

#ifndef Node_h
#define Node_h

class Node
{
    public:
        int data;
        Node* link;

        Node();
        Node(int data_);
};

Node::Node()
{
    link = nullptr;
}

Node::Node(int data_)
{
    data = data_;
    link = nullptr;
}

#endif