/// Source : https://leetcode.com/problems/integer-to-roman/description/                                                                                                        
/// Author : yanming
/// Time   : 2019-05-22

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

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: 3
Output: "III"
Example 2:

Input: 4
Output: "IV"
Example 3:

Input: 9
Output: "IX"
Example 4:

Input: 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 5:

Input: 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

#include <iostream>
#include <vector>
#include <cmath>

/// Ad-Hoc
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    std::string intToRoman(int num) {
        std::string res = "";
        for (int n = 0; n < 7; n += 2) {
            int x = num / value[n];
            std::cout << x << "n = " << n << std::endl;
            if (x < 4) {
                for (int i = 0; i < x; ++i) {
                    res += roman[n]; 
                }
            } else if (x == 4) {
                res = res + roman[n] + roman[n-1];
            } else if (x > 4 && x < 9) {
                res += roman[n-1];
                for (int i = 5; i < x; ++i) {
                    res += roman[n];
                }
            } else if (x == 9) {
                res = res + roman[n] + roman[n-2];
            }

            num %= value[n];
        }
        return res;
    }

private:
    std::vector<char> roman{'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    std::vector<int> value{1000, 500, 100, 50, 10, 5, 1};
};

int main() {

    std::vector<int> nums1 = {1, 1};
    std::cout << nums1[-1] << std::endl;
    std::cout << "III compare now " << Solution().intToRoman(3) << std::endl; // III
    std::cout << "IV compare now " << Solution().intToRoman(4) << std::endl; // IV
    std::cout << "IX compare now " << Solution().intToRoman(9) << std::endl; // IX
    std::cout << "LVIII compare now " << Solution().intToRoman(58) << std::endl; // LVIII
    std::cout << "MCMXCIV compare now " << Solution().intToRoman(1994) << std::endl; // MCMXCIV
    return 0;
}
