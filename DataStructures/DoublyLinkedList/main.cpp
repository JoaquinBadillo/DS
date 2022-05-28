#include "list.hpp"

int main(void)
{
    List list;

    std::cout << "Print empty list:\n";
    list.print();

    std::cout << "\nAdd items to list and print:\n";
    for (int i=10; i>0; i--)
    {
        list.insert(i);
    }

    list.print();

    std::cout << "\nPrint list using [] operator (accesing elements):\n";
    for (int i=0; i < list.size; i++)
    {
        std::cout << list[i] << " -> ";  
    }
    std::cout << "//\n";


    std::cout << "\nInsert 0 at the beginning:\n";
    list.insert(0);
    list.print();

    std::cout << "\nInsert 7 at the 5th index:\n";
    list.insert(7, 5);
    list.print();

    std::cout << "\nChange element on the 5th index to 6:\n";
    list.modify(6, 5);
    list.print();

    std::cout << "\nChange element on the 5th index to 3 (using [] operator):\n";
    list[5] = 3;
    list.print();

    std::cout << "\nRemove element on the 5th index:\n";
    list.remove(5);
    list.print();
    return 0;
}