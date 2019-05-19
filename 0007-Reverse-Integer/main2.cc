/// Source : https://leetcode.com/problems/reverse-integer/description/
/// Author : yanming
/// Time   : 2019-05-18

/***
Given a 32-bit signed integer, reverse digits of an integer

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

#include<bits/stdc++.h>
#include <iostream>

using namespace std;

/// Using digit vector to solve the overflow problem
/// Time Complexity: O(logx)
/// Space Complexity: O(logx)

class Solution {
public:
    int reverse(int x) {
        if (x == 0) {
            return x;
        }

        if (x == INT_MIN) {
            return 0;
        }

        int sign = x > 0 ? 1 : -1;
        std::vector<int> reverseDigits;
        x = abs(x);
        while(x) {
            reverseDigits.push_back(x%10);
            x /= 10;
        }

        if (sign > 0 && overflow(reverseDigits, {2, 1, 4, 7, 4, 8, 3, 6, 4, 7})) {
            return 0;
        } else if (sign < 0 && overflow(reverseDigits, {2, 1, 4, 7, 4, 8, 3, 6, 4, 8})) {
            return 0;
        }
        // std::cout << "sign = " << sign << std::endl;
        return sign * getNumber(reverseDigits);
    }

private:
    int getNumber(const vector<int> &digits) {
        int res = 0;
        for (int digit : digits) {
            res = res * 10 + digit;
        }
        // std::cout << "res" << res << std::endl;        
        return res;
    }

    bool overflow(std::vector<int>& digits, const std::vector<int>& max) {
        if (digits.size() < max.size()) {
            return false;
        }

        assert(digits.size() == max.size());
        for(int i = 0;i < digits.size(); ++i) {
            if (digits[i] > max[i])
                return true;
            else if (digits[i] < max[i])
                return false;
        }

        return false;
    }

};


int main() {
//    cout << INT_MAX << endl; // 2147483647
//    cout << INT_MIN << endl; // -2147483648

    cout << Solution().reverse(123) << endl;
    cout << Solution().reverse(-123) << endl;
    cout << Solution().reverse(12) << endl;
    cout << Solution().reverse(INT_MAX) << endl;
    cout << Solution().reverse(INT_MIN) << endl;
                   
    return 0;
}
    
