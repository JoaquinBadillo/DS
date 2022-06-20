// Doubly Integer Linked List

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

template<typename dtype> class List
{
    private:
        // Insert item at the beginning: O(1)
        void insert(Node<dtype>& item);
        // Insert item at a given index: O(n)
        void insert(Node<dtype>& item, int i); 
    public:
        Node<dtype>* head;
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

template<typename dtype> List<dtype>::List()
{
    size = 0;
    head = nullptr;
}

template<typename dtype> List<dtype>::~List()
{
    Node<dtype>* current = head;
    Node<dtype>* next;

    while (current != nullptr)
    {
        next = current -> next;
        delete current;
        current = next;
    }
}

template<typename dtype> dtype& List<dtype>::access(int i)
{
    Node<dtype>* item = head;

    if (i < size)
    {
        for(int j = 0; j < i; j++)
        {
            item = item -> next;
        }
        return item -> data;
    }

    throw ListException("Error: Index doesn't exist!");
}

template<typename dtype> dtype& List<dtype>::operator[](int i)
{
    return this -> access(i);
}

template<typename dtype> void List<dtype>::modify(dtype data, int i)
{
    Node<dtype>* item = head;

    if (i >= size)
    {
        throw ListException("Error: Index doesn't exist!");
    }

    for(int j = 0; j < i; j++)
    {
        item = item -> next;
    }

    item -> data = data;    
}

template<typename dtype> void List<dtype>::insert(Node<dtype>& item)
{
    item.next = head;
    if (head != nullptr)
    {
        head -> prev = &item;
    }
    head = &item;
    size++;
}

template<typename dtype> void List<dtype>::insert(dtype data)
{
    Node<dtype>* itemptr = new Node<dtype>(data);
    this -> insert(*itemptr);
}

template<typename dtype> void List<dtype>::insert(Node<dtype>& item, int i)
{
    Node<dtype>* current = head;

    if (i > size)
    {
        delete &item;
        throw ListException("Error: Index doesn't exist!");
    }

    else if (i == 0)
    {
        this -> insert(item);
        return;
    }

    for (int j = 0; j < i-1; j++)
    {
        current = current -> next;
    }

    item.prev = current;
    item.next = current -> next;
    item.prev -> next = &item;
    current -> prev = &item;
    size++;
}

template<typename dtype> void List<dtype>::insert(dtype data, int i)
{
    Node<dtype>* itemptr = new Node<dtype>(data);
    this -> insert(*itemptr, i);
}

template<typename dtype> void List<dtype>::remove(int i)
{
    Node<dtype>* current = head;

    if (i >= size)
    {
        throw ListException("Error: Index doesn't exist!");
    }

    for (int j = 0; j < i; j++)
    {
        current = current -> next;
    }

    (current -> prev) -> next = current -> next;
    (current -> next) -> prev = current -> prev;

    delete current;

    size--;
}

template<typename dtype> void List<dtype>::print()
{
    if (size == 0)
    {
        std::cout << "Empty List\n";
        return;
    }

    Node<dtype>* current;

    for(current = head; current != nullptr; current = current -> next)
    {
        std::cout << current -> data << " -> ";
    }

    std::cout << "//\n";
}

#endif