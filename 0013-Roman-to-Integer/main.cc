/// Source : https://leetcode.com/problems/roman-to-integer/description/                                                                                                     
/// Author : yanming
/// Time   : 2019-05-24

/***
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V () and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: "III"
Output: 3
Example 2:

Input: "IV"
Output: 4
Example 3:

Input: "IX"
Output: 9
Example 4:

Input: "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 5:

Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4
*/

#include <iostream>
#include <unordered_map>

/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int romanToInt(std::string s) {
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i + 1 < s.size() && maps[s[i]] < maps[s[i+1]]) {
                res += maps[s[i+1]] - maps[s[i]];
                ++i;
            } else {
                res += maps[s[i]];
            }
        }        
        return res;
    }

private:
    std::unordered_map<char, int> maps{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
};

int main() {

    std::cout << "3 compare now " << Solution().romanToInt("III") << std::endl; // III
    std::cout << "4 compare now " << Solution().romanToInt("IV") << std::endl; // IV
    std::cout << "9 compare now " << Solution().romanToInt("IX") << std::endl; // IX
    std::cout << "58 compare now " << Solution().romanToInt("LVIII") << std::endl; // LVIII
    std::cout << "1994 compare now " << Solution().romanToInt("MCMXIV") << std::endl; // MCMXCIV
    return 0;
}
