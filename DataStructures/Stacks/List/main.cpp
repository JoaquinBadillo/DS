#include "stack.hpp"
#include <iostream>

int main(void)
{
    Stack<int> s;

    for (int i = 0; i < 15; i++)
    {
        s.Push(i);
    }

    try
    {
        for (int i = 15; i > 0; i--)
        {
            std::cout << s.Pop() << std::endl;
        }

    } catch(StackException e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
    
    
}