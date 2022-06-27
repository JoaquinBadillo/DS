/* Problem: 
Given an integer written in roman numerals, return its equivalent decimal representation */

#include <string>
#include <iostream>

#include <unordered_map>
class Solution
{
    private:
        std::unordered_map<char, int> conversion = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};

    public:
        int romanToInt(std::string s)
        {
            int n = s.length();
            int number = 0;

            int current = conversion.find(s[0])->second;

            for (int i = 0; i < n - 1; i++)
            {
                int next = conversion.find(s[i + 1])->second;

                if (current < next)
                {
                    number -= current;
                }
                else
                {
                    number += current;
                }

                current = next;
            }
            
            number += conversion.find(s[n - 1])->second;
            return number;
        }
};

int main(void)
{
    Solution s;

    std::cout << ((s.romanToInt("XIII") == 13) ? "Passed\n" : "Failed\n");
    std::cout << ((s.romanToInt("IV") == 4) ? "Passed\n" : "Failed\n");
    std::cout << ((s.romanToInt("XLII") == 42) ? "Passed\n" : "Failed\n");
    std::cout << ((s.romanToInt("XC") == 90) ? "Passed\n" : "Failed\n");
    std::cout << ((s.romanToInt("XVI") == 16) ? "Passed\n" : "Failed\n");
    std::cout << ((s.romanToInt("XXIV") == 24) ? "Passed\n" : "Failed\n");
    std::cout << ((s.romanToInt("MMXXII") == 2022) ? "Passed\n" : "Failed\n");
    std::cout << ((s.romanToInt("MCMXCIX") == 1999) ? "Passed\n" : "Failed\n");
}