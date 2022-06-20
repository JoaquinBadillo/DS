// Linked List Item
#ifndef Node_h
#define Node_h

template<typename dtype> class Node
{
    public:
        dtype data;
        Node<dtype>* link;

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

#endif