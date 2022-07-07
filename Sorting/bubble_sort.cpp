#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>

using namespace std;

void printVector(vector<int> list)
{
    // Print first 20 elements
    cout << "[";
    for(int i=0; i < 19; i++)
    {
        cout << list[i] << ", ";
    }
    cout << list[19] << ", ...]" << endl;
}

vector<int> bubbleSort(vector<int> list)
{
    int n = list.size();
    int swaps = -1;

    do{
        swaps = 0;
        for(int i=0; i<n-1; i++)
        {
            if(list[i] > list[i+1])
            {
                int bigger = list[i];
                list[i] = list[i+1];
                list[i+1] = bigger;
                swaps++;
            }
        }
    }while(swaps > 0);

    return list;
}

int main(void)
{
    srand(time(0));
    vector<int> List;
    
    for(int i=0; i<100; i++)
    {
        List.push_back(1 + rand() % 100);
    }

    cout << "Original list (first 20 elements):" << endl;
    printVector(List);
    cout << endl;

    List = bubbleSort(List);
    cout << "Sorted list (first 20 elements):" << endl;
    printVector(List);
    
    return 0;
}