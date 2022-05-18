// Integer Linked List
#include <iostream>
#include "node.hpp"

class List
{
    public:
        Node* first;
        int size;

        List();

        // Access linked list: O(n)
        int& access(int i);

        // Access linked list: O(n)
        int& operator[](int i);

        // Modify linked list item: O(n)
        void modify(int data, int i);

        // Insert item at the beginning: O(1)
        void insert(Node& item);

        // Insert item at a given index: O(n)
        void insert(Node& item, int i); 

        // Deletion: O(n)
        void remove(int i);

        // Print list: O(n)
        void print();     
};

List::List()
{
    size = 0;
    first = nullptr;
}

int& List::access(int i)
{
    // Access element at ith index
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
    // Modify element at ith index

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
    // Insert at the beginning

    item.link = first;
    first = &item;
    size++;
}

void List::insert(Node& item, int i)
{
    // Insert at the ith position

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

void List::remove(int i)
{
    // Remove item at index i

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

void List::print()
{
    Node* temp;

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