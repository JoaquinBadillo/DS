#include <iostream>
#include <vector>
#include <iomanip>
#include <ctime>

using namespace std;

vector<int> merge(vector<int> list1, vector<int> list2)
{
    vector<int> sortedList;

    int length1 = list1.size();
    int length2 = list2.size();

    int i = 0;
    int j = 0;

    while(i<length1)
    {
        if(list1[i] <= list2[j])
        {
            sortedList.push_back(list1[i]);
            i++;
        }
        else if(j < length2)
        {
            sortedList.push_back(list2[j]);
            j++;
        }
        else
        {
            sortedList.push_back(list1[i]);
            i++;
        }
    }

    while(j<length2)
    {
        sortedList.push_back(list2[j]);
        j++;
    }

    return sortedList;
}

vector<int> mergeSort(vector<int> list, int l, int r)
{
    int middle = (l + r) / 2;

    if(r-1 == l)
    {
        vector<int> sortedList;
        sortedList.push_back(list[l]);
        return sortedList;
    }
    else
    {
        vector<int> left = mergeSort(list, l, middle);
        vector<int> right = mergeSort(list, middle, r);
        return merge(left, right);
    }
}

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

int main(void)
{
    srand(time(0));
    vector<int> list;
    int n = 100;
    for(int i=0; i<n; i++)
    {
        list.push_back(1 + rand() % 100);
    }

    cout << "Original list:" << endl;
    printVector(list);
    cout << endl;

    vector<int> sortedList = mergeSort(list, 0, n);
    cout << "Merge Sort:" << endl;
    printVector(sortedList);
    
    return 0;
}