#ifndef Stack_h
#define Stack_h

#include <string>
#include "node.hpp"

class StackException : public std::exception {
    private:
    std::string message;

    public:
    StackException(std::string msg)
    {
        message = msg;
    }

    const char * what ()
    {
        return message.c_str();
    }
};

template <typename dtype> class Stack
{
    public:
        Node<dtype>* top;

        Stack();
        ~Stack();

        void Push(dtype x);
        dtype Pop();
};

template <typename dtype> Stack<dtype>::Stack()
{
    this -> top = nullptr;
}

template <typename dtype> Stack<dtype>::~Stack()
{
    while (top != nullptr)
    {
        this -> Pop();
    }
}

template <typename dtype> dtype Stack<dtype>::Pop()
{
    // Get top of stack
    Node<dtype>* prev = top;

    // Check if top is assigned to a node
    if (top == nullptr)
    {
        throw StackException("Cannot pop empty stack");
    }

    // Get value
    dtype value = this -> top -> data;

    // Remove top
    this -> top = this -> top -> link;
    delete prev;

    return value;
}

template <typename dtype> void Stack<dtype>::Push(dtype x)
{
    Node<dtype>* newItem = new Node<dtype>(x);
    Node<dtype>* prev = top;
    this -> top = newItem;
    top -> link = prev;
}
#endif