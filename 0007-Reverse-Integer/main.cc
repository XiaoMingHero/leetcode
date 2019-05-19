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

/// Using long long to solve the overflow problem
/// Time Complexity: O(logx)
/// Space Complexity: O(logx)

class Solution {
public:
    int reverse(int x) {
        if (x == 0) {
            return x;
        }
        int sign = x > 0 ? 1 : -1;
        
        long long num = abs(x);
        long long reverse_num = 0;
        
        while(num) {
            reverse_num = reverse_num * 10 + num % 10;
            num /= 10;
        }

        reverse_num *= sign;
        if (reverse_num > INT_MAX || reverse_num < INT_MIN) {
            return 0; 
        }

        return reverse_num;
    }
};


int main() {
    cout << Solution().reverse(123) << endl;
    cout << Solution().reverse(-123) << endl;
    cout << Solution().reverse(12) << endl;
    cout << Solution().reverse(INT_MAX) << endl;
    cout << Solution().reverse(INT_MIN) << endl;
                   
    return 0;
}
    
