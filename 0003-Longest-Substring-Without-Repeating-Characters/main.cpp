//
// Created by xuyanming on 2019-05-18.
// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
//

/**
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include <iostream>
#include <vector>
#include <cassert>

// Sliding Window
// Time Complexity: O(len(s))
// Space Complexity: O(len(charset))
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int freq[256] = {0};
        int l = 0, r = -1; // slide windows: s[l,r]
        int res = 0;
        
        while(r + 1 < s.size()) {
            if (freq[s[r+1]] == 0) {
                freq[s[++r]]++;
            } else {
                freq[s[l++]]--;
            }

            res = std::max(res, r - l + 1);
        }
        return res;
    }
};



int main() {
    std::cout << Solution().lengthOfLongestSubstring( "abcabcbb" )<<std::endl; //3
    std::cout << Solution().lengthOfLongestSubstring( "bbbbb" )<<std::endl;    //1
    std::cout << Solution().lengthOfLongestSubstring( "pwwkew" )<<std::endl;   //3
    std::cout << Solution().lengthOfLongestSubstring( "c" )<<std::endl;        //1
    std::cout << Solution().lengthOfLongestSubstring( "" )<<std::endl;         //0
    return 0;
}
