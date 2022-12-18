#include <bits/stdc++.h>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> hashset;
        std::vector<int>::iterator it;
        for (it = nums.begin(); it < nums.end(); it++) {
            if (hashset.find(*it) != hashset.end()) {
                return true;
            }
            hashset.insert(*it);
        }
        return false;
    }
};