// Implementation of List Algorithms

#ifndef ListAlgorithms_h
#define ListAlgorithms_h

#include <iostream>
#include "list.hpp"

// Print a list recursively given its head pointer: Time Complexity O(n)
void printRecursive(Node* item)
{
    if (item == nullptr)
    {
        std::cout << "//\n"; 
        return;
    }

    std::cout << item -> data << " -> ";
    printRecursive(item -> link); 
}

// Print list in reverse order recursively: Time Complexity O(n)
void printReverse(Node* item)
{
    if (item == nullptr)
    {
        std::cout << "//"; 
        return;
    } 

    printReverse(item -> link); 
    std::cout << " <- " << item -> data;
}

// Reverse linked list: Time Complexity O(n)
void reverseList(List& list)
{
    Node* prev = nullptr; // Previous element in the list
    Node* current = nullptr; // Current element address in the list
    Node* next = list.first;

    while(next != nullptr)
    {
        current = next;
        next = current -> link;
        current -> link = prev;
        prev = current; 
    }

    list.first = prev;
}

// Reverse linked list recursively: Time Complexity O(n)
void reverseRecursive(List& list, Node* item)
{
    if (item -> link == nullptr)
    {
        list.first = item; // Head points to last item
        return;
    }

    Node* next = item -> link;

    reverseRecursive(list, next); // Change pointer of next item

    next -> link = item; // Change next item to point to current item
    item -> link = nullptr; // Set end of list
}

// Reverse linked list recursively: Time Complexity O(n)
void reverseRecursive(List& list)
{
    // This function was added to use only the list as a parameter
    reverseRecursive(list, list.first);
}

#endif