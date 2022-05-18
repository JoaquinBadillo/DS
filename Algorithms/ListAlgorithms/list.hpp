// Integer Linked List

#ifndef List_h
#define List_h

#include <iostream>
#include "node.hpp"

class List
{
    public:
        Node* first;
        int size;

        List();
        ~List();

        // Access linked list: O(n)
        int& access(int i);
        // Access linked list: O(n)
        int& operator[](int i);
        // Modify linked list item: O(n)
        void modify(int data, int i);
        // Insert item at the beginning: O(1)
        void insert(Node& item);
        // Create node and insert item at the beginning: O(1)
        void insert(int data);
        // Insert item at a given index: O(n)
        void insert(Node& item, int i); 
        // Create node and insert item at a given index: O(n)
        void insert(int data, int i); 
        // Delete item at ith position: O(n)
        void remove(int i);   
};

List::List()
{
    size = 0;
    first = nullptr;
}

List::~List()
{
    Node* currentItem = first;
    Node* nextItem;
    while(currentItem != nullptr)
    {
        nextItem = currentItem -> link;
        delete currentItem;
        currentItem = nextItem;
    }
}

int& List::access(int i)
{
    Node* temp = first;

    if (i < size)
    {
        for(int j=0; j<i; j++)
        {
            temp = temp -> link;
        }

        return temp->data;
    }

    throw "Error: Index doesn't exist!"; 
}

int& List::operator[](int i)
{
    return this -> access(i);
}

void List::modify(int data, int i)
{
    Node* temp = first;

    if (i >= size)
    {
        throw "Error: Index doesn't exist!";
    }

    for(int j=0; j<i; j++)
    {
        temp = temp -> link;
    }

    temp->data = data;
}

void List::insert(Node& item)
{
    item.link = first;
    first = &item;
    size++;
}

void List::insert(int data)
{
    Node* nodeptr = new Node(data);
    this -> insert(*nodeptr);
}

void List::insert(Node& item, int i)
{
    Node* temp = first;
    
    if (i >= size)
    {
        throw "Error: Index doesn't exist";
    }

    for(int j=0; j<i-1; j++)
    {
        temp = temp -> link;
    }
    
    item.link = temp -> link;
    temp -> link = &item;
    size++;
}

void List::insert(int data, int i)
{
    Node* nodeptr = new Node(data);
    this -> insert(*nodeptr, i);
}

void List::remove(int i)
{
    Node* temp = first;
    Node* next;

    if (i>=size)
    {
        throw "Error: Index doesn't exist";
    }

    for(int j=0; j<i-1; j++)
    {
            temp = temp -> link;
    }

    next = temp -> link -> link;
    delete temp -> link;

    temp -> link = next;
}
#endif