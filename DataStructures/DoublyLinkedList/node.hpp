// List Item
#ifndef Node_h
#define Node_h

template <typename dtype> class Node
{
    public:
        dtype data;
        Node<dtype>* prev;
        Node<dtype>* next;

        Node();
        Node(dtype data_);
};

template<typename dtype> Node<dtype>::Node()
{
    prev = nullptr;
    next = nullptr;
}

template<typename dtype> Node<dtype>::Node(dtype data_)
{
    data = data_;
    prev = nullptr;
    next = nullptr;
}

#endif