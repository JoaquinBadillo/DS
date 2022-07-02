#include <vector>
#include <algorithm>

using namespace std;

// Solution1 has a time complexity of O(n lg(n))
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> nums2;
        copy(nums.begin(), nums.end(), back_inserter(nums2)); // O(n)
        sort(nums.begin(), nums.end()); // O(n lg(n))
        
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        
        int sum = nums[i] + nums[j];
        
        // O(lg(n))
        while(sum != target) // Assuming solution exists
        {
            if (sum < target)
            {
                i++;
            }
            else if (sum > target)
            {
                j--;
            }
            
            sum = nums[i] + nums[j];
        }
        
        // O(n)
        for(int k = 0; k < n; k++)
        {
            if(nums[i] == nums2[k])
            {
                i = k;
                break;
            }
        }
        
        // O(n)
        for(int k = n - 1; k > -1; k--)
        {
            if(nums[j] == nums2[k])
            {
                j = k;
                break;
            }
        }
        
        vector<int> answer{i, j};
        return answer;
    }
};

#include <unordered_map>
// Solution 2 has an average time complexity of O(n)
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> remainderMap;
        int i = -1;
        int j = -1;

        // Average: O(n)
        vector<int>::iterator vit;
        for (vit = nums.begin(); vit != nums.end(); vit++) {
            int value = *vit;
            int remainder = target - *vit;
             remainderMap.insert({remainder, value});
        }
        
        // Average: O(n)
        for (vit = nums.begin(); vit != nums.end(); vit++) {
            unordered_map<int, int>::iterator it = remainderMap.find(*vit);
            
            if (it != remainderMap.end()){
                int n1 = it -> first;
                int n2 = it -> second;
                
                for (int n = 0; n < nums.size(); n++) {
                    if (nums[n] == n1) {
                        i = n;
                        break;
                    }
                }
                
                for (int n = 0; n < nums.size(); n++) {
                    if ((nums[n] == n2) && (n != i)) {
                        j = n;
                        break;
                    }
                }
                
                if ((i != -1) && (j != -1)) {
                    break;
                }
            }
        }
        
        vector<int> answer{i, j};
        return answer;    
    }
};