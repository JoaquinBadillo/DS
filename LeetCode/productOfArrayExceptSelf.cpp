#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> answer;
        
        int n = nums.size();
        int everythingBefore[n];
        everythingBefore[0] = 1;
        
        int everythingAfter[n];
        everythingAfter[n-1] = 1;
        
        for (int i = 1; i < n; i++) {
            everythingBefore[i] = everythingBefore[i-1] * nums[i-1];
            everythingAfter[n-1-i] = everythingAfter[n-i] * nums[n-i]; 
        }
        
        for (int i = 0; i < n; i++) {
            answer.push_back(everythingBefore[i] * everythingAfter[i]);
        }
        
        return answer;
    }
};