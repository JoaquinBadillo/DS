// Integer Linked List Item

template<typename dtype> class Node
{
    public:
        dtype data;
        Node* link;

        Node();
        Node(dtype data_);
};

template<typename dtype> Node<dtype>::Node()
{
    link = nullptr;
}

template<typename dtype> Node<dtype>::Node(dtype data_)
{
    data = data_;
    link = nullptr;
}