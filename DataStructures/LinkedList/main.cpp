#include "list.hpp"
#include "listAlgorithms.hpp"

int main(void)
{
    // Test List
    try
    {
        List<int> list;

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

        std::cout << "\nAdd element on the 20th index (testing exception):\n";
        list.insert(5, 20);
        list.print();
    } catch(ListException e) {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\nTest List Algorithms\n";
    
    // Test List Algorithms
    try
    {
        List<int> list;

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
    } catch(ListException e) {
        std::cerr << e.what() << '\n';
    }
    return 0;
}