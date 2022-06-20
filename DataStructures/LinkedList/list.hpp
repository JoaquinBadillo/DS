// Linked List
#ifndef List_h
#define List_h

#include <iostream>
#include "node.hpp"


class ListException : public std::exception {
    private:
    std::string message;

    public:
    ListException(std::string msg)
    {
        message = msg;
    }

    const char * what ()
    {
        return message.c_str();
    }
};


template <typename dtype> class List
{
    private:
        // Insert item at the beginning: O(1)
        void insert(Node<dtype>& item);

        // Insert item at a given index: O(n)
        void insert(Node<dtype>& item, int i); 
    public:
        Node<dtype>* first;
        int size;

        List();
        ~List();

        // Access linked list: O(n)
        dtype& access(int i);
        // Access linked list: O(n)
        dtype& operator[](int i);
        // Modify linked list item: O(n)
        void modify(dtype data, int i);
        // Create node and insert item at the beginning: O(1)
        void insert(dtype data);
        // Create node and insert item at a given index: O(n)
        void insert(dtype data, int i); 
        // Delete item at ith position: O(n)
        void remove(int i);
        // Print list: O(n)
        void print();     
};

template <typename dtype> List<dtype>::List()
{
    size = 0;
    first = nullptr;
}

template <typename dtype> List<dtype>::~List()
{
    Node<dtype>* currentItem = first;
    Node<dtype>* nextItem;
    while(currentItem != nullptr)
    {
        nextItem = currentItem -> link;
        delete currentItem;
        currentItem = nextItem;
    }
}

template <typename dtype> dtype& List<dtype>::access(int i)
{
    Node<dtype>* temp = first;

    if (i < size)
    {
        for(int j=0; j<i; j++)
        {
            temp = temp -> link;
        }

        return temp->data;
    }

    throw ListException("Error: Index doesn't exist!"); 
}

template <typename dtype> dtype& List<dtype>::operator[](int i)
{
    return this -> access(i);
}

template <typename dtype> void List<dtype>::modify(dtype data, int i)
{
    Node<dtype>* temp = first;

    if (i >= size)
    {
        throw ListException("Error: Index doesn't exist!");
    }

    for(int j=0; j<i; j++)
    {
        temp = temp -> link;
    }

    temp->data = data;
}

template <typename dtype> void List<dtype>::insert(Node<dtype>& item)
{
    item.link = first;
    first = &item;
    size++;
}

template <typename dtype> void List<dtype>::insert(dtype data)
{
    Node<dtype>* nodeptr = new Node<dtype>(data);
    this -> insert(*nodeptr);
}

template <typename dtype> void List<dtype>::insert(Node<dtype>& item, int i)
{
    Node<dtype>* temp = first;
    
    if (i > size)
    {
        delete &item;
        throw ListException("Error: Index is out of range");
    }
    
    else if (i == 0)
    {
        this -> insert(item);
        return;
    }
    
    for(int j=0; j<i-1; j++)
    {
        temp = temp -> link;
    }
    
    item.link = temp -> link;
    temp -> link = &item;
    size++;
}

template <typename dtype> void List<dtype>::insert(dtype data, int i)
{
    Node<dtype>* nodeptr = new Node<dtype>(data);
    this -> insert(*nodeptr, i);
}

template <typename dtype> void List<dtype>::remove(int i)
{
    Node<dtype>* temp = first;
    Node<dtype>* next;

    if (i>=size)
    {
        throw ListException("Error: Index doesn't exist");
    }

    for(int j=0; j<i-1; j++)
    {
        temp = temp -> link;
    }

    next = temp -> link -> link;
    delete temp -> link;
    temp -> link = next;

    size--;
}

template <typename dtype> void List<dtype>::print()
{
    Node<dtype>* temp;

    if(size >0)
    {
        for(temp = first; temp != nullptr; temp = temp -> link)
        {
            std::cout << temp -> data << " -> ";
        }
        std::cout << "//\n";
    }
    else
    {
        std::cout << "Empty list\n"; 
    }
}

#endif