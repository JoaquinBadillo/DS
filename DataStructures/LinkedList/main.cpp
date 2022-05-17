#include "list.hpp"

int main(void)
{
    List list;
    Node* itemptr;

    std::cout << "Print empty list:\n";
    list.print();

    std::cout << "\nAdd items to list and print:\n";
    for (int i=10; i>0; i--)
    {
        itemptr = new Node(i);
        list.insert(*itemptr);
    }

    list.print();

    std::cout << "\nCheck accessing:\n";
    std::cout << "[";
    for (int i=0; i < list.size - 1; i++)
    {
        std::cout << list[i] << ", ";  
    }
    std::cout << list[list.size - 1] << "]\n";


    std::cout << "\nInsert 0 at the beginning:\n";
    itemptr = new Node(0);
    list.insert(*itemptr);
    list.print();

    std::cout << "\nInsert 7 at the 5th index:\n";
    itemptr = new Node(7);
    list.insert(*itemptr, 5);
    list.print();

    std::cout << "\nChange element on the 5th index to 6:\n";
    list.modify(5, 5);
    list.print();

    std::cout << "\nRemove element on the 2nd index\n";
    list.remove(2);
    list.print();
    return 0;
}