#include <vector>
#include <algorithm>

class MyHashSet {
public:
    std::vector<int> arr [10000];
    
    MyHashSet();

    // Hash function
    int hash(int key);

    // Insertion
    void add(int key);

    // Deletion
    void remove(int key);
    
    // "Find"
    bool contains(int key);
    
};

MyHashSet::MyHashSet() {

}

int MyHashSet::hash(int key) {
        return key % 10000;
}
    
void MyHashSet::add(int key) {
    int bucket = hash(key);
    std::vector<int>::iterator it = std::find(arr[bucket].begin(), arr[bucket].end(), key);
    if (it == arr[bucket].end())
    {
        arr[bucket].push_back(key);
    }
}

void MyHashSet::remove(int key) {
    int bucket = hash(key);
    std::vector<int>::iterator it = std::find(arr[bucket].begin(), arr[bucket].end(), key);
    if (it != arr[bucket].end())
    {
        arr[bucket].erase(it);
    }   
}

bool MyHashSet::contains(int key) {
    int bucket = hash(key);
    std::vector<int>::iterator it = std::find(arr[bucket].begin(), arr[bucket].end(), key);
    
    return it != arr[bucket].end();
}