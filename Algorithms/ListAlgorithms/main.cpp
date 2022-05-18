// Test algorithms

#include "listAlgorithms.hpp"

int main(void)
{
    List list;

    for(int i=1; i<11; i++)
    {
        list.insert(i);
    } 

    std::cout << "Print list recursively: \n";
    printRecursive(list.first);

    std::cout << "\nPrint list recursively in reverse order: \n";
    printReverse(list.first);
    std::cout << "\n";

    std::cout << "\nReverse list (iteratively): \n";
    reverseList(list);
    printRecursive(list.first);

    std::cout << "\nReverse list again (recursively): \n";
    reverseRecursive(list);
    printRecursive(list.first);

    return 0;
}