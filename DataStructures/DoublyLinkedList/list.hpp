#ifndef List_h
#define List_h
// Doubly Integer Linked List

#include <iostream>
#include <string>
#include <vector>
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

class List
{
    private:
        // Insert item at the beginning: O(1)
        void insert(Node& item);
        // Insert item at a given index: O(n)
        void insert(Node& item, int i); 
    public:
        Node* head;
        int size;

        List();
        ~List();

        // Access linked list: O(n)
        int& access(int i);
        // Access linked list: O(n)
        int& operator[](int i);
        // Modify linked list item: O(n)
        void modify(int data, int i);
        // Create node and insert item at the beginning: O(1)
        void insert(int data);
        // Create node and insert item at a given index: O(n)
        void insert(int data, int i); 
        // Delete item at ith position: O(n)
        void remove(int i);
        // Print list: O(n)
        void print(); 
};

List::List()
{
    size = 0;
    head = nullptr;
}

List::~List()
{
    Node* current = head;
    Node* next;

    while (current != nullptr)
    {
        next = current -> next;
        delete current;
        current = next;
    }
}

int& List::access(int i)
{
    Node* item = head;

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

int& List::operator[](int i)
{
    return this -> access(i);
}

void List::modify(int data, int i)
{
    Node* item = head;

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

void List::insert(Node& item)
{
    item.next = head;
    if (head != nullptr)
    {
        head -> prev = &item;
    }
    head = &item;
    size++;
}

void List::insert(int data)
{
    Node* itemptr = new Node(data);
    this -> insert(*itemptr);
}

void List::insert(Node& item, int i)
{
    Node* current = head;

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

void List::insert(int data, int i)
{
    Node* itemptr = new Node(data);
    this -> insert(*itemptr, i);
}

void List::remove(int i)
{
    Node* current = head;

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

void List::print()
{
    if (size == 0)
    {
        std::cout << "Empty List\n";
        return;
    }

    Node* current;

    for(current = head; current != nullptr; current = current -> next)
    {
        std::cout << current -> data << " -> ";
    }

    std::cout << "//\n";
}

#endif