// Implementation of some List Algorithms (printing and reversing)

#ifndef ListAlgorithms_h
#define ListAlgorithms_h

#include <iostream>
#include "list.hpp"

// Print a list recursively given its head pointer: Time Complexity O(n)
template <typename T> void printRecursive(Node<T>* item)
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
template <typename T> void printReverse(Node<T>* item)
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
template <typename T> void reverseList(List<T>& list)
{
    Node<T>* prev = nullptr; // Previous element in the list
    Node<T>* current = nullptr; // Current element address in the list
    Node<T>* next = list.first;

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
template <typename T> void reverseRecursive(List<T>& list, Node<T>* item)
{
    if (item -> link == nullptr)
    {
        list.first = item; // Head points to last item
        return;
    }

    Node<T>* next = item -> link;

    reverseRecursive(list, next); // Change pointer of next item

    next -> link = item; // Change next item to point to current item
    item -> link = nullptr; // Set end of list
}

// Reverse linked list recursively: Time Complexity O(n)
template <typename T> void reverseRecursive(List<T>& list)
{
    // This function was added to use only the list as a parameter
    reverseRecursive(list, list.first);
}

#endif