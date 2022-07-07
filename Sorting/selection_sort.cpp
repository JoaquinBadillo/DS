#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>

using namespace std;

void printVector(vector<int> list)
{
    int n = list.size();

    cout << "[";
    for(int i=0; i < n - 1; i++)
    {
        cout << list[i] << ", ";
    }
    cout << list[n-1] << "]" << endl;
}

vector<int> selectionSort(vector<int> list)
{
    int n = list.size();

    for(int j=0; j<n; j++)
    {
        int smallest = list[j];
        int index = j;

        for(int i=j; i<n; i++)
        {
            if(list[i] < smallest)
            {
                smallest = list[i];
                index = i;
            }
        }

        list[index] = list[j];
        list[j] = smallest;
    } 
    return list;
}

int main(void)
{
    srand(time(0));
    vector<int> List;
    
    for(int i=0; i<20; i++)
    {
        List.push_back(1 + rand() % 100);
    }

    cout << "Original list:" << endl;
    printVector(List);
    cout << endl;

    List = selectionSort(List);
    cout << "Sorted list:" << endl;
    printVector(List);
    
    return 0;
}