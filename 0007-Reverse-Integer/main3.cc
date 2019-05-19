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

/// Poping digit one by one and check before overflow
/// Time Complexity: O(logx)
/// Space Complexity: O(1)

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
        x = abs(x);
        int reverseNum = 0;
        while(x) {
            if (reverseNum > INT_MAX / 10 || (reverseNum == INT_MAX / 10 && x % 10 > 7))
                return 0;
            
            reverseNum = reverseNum * 10 + x % 10;
            x /= 10;
        }

        return sign * reverseNum;
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
    
