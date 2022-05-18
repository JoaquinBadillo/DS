// Integer Linked List Item

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