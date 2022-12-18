#include <vector>
class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        std::vector<int>::iterator it;
        int value = 0;
        
        for (it = nums.begin(); it < nums.end(); it++) {
            value = value ^ *it;
        }
        
        return value;
    }
};