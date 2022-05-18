#include <iostream>
#include "list.hpp"

// Reverse linked list: Time Complexity O(n)
void reverseList(List& l)
{
    
    Node* prev = nullptr; // Previous element in the list
    Node* current = nullptr; // Current element address in the list
    Node* next = l.first;

    while(next != nullptr)
    {
        current = next;
        next = current -> link;
        current -> link = prev;
        prev = current; 
    }

    l.first = prev;
}

int main(void)
{
    List list;
    for(int i=1; i<10; i++)
    {
        list.insert(i);
    }

    std::cout << "Current list:\n"; 
    list.print();

    reverseList(list);

    std::cout << "\nReversed list:\n";
    list.print();

    return 0;
}