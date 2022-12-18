#include <bits/stdc++.h>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int min = prices[0];
        int maxprofit = 0;

        std::vector<int>::iterator it;
        for (it = prices.begin(); it < prices.end(); it++) {
            if (*it < min) {
                min = *it;
            }
            else if (*it - min > maxprofit) {
                maxprofit = *it - min;
            }
        }

        return maxprofit;
    }
};