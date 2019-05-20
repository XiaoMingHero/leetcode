/// Source : https://leetcode.com/problems/container-with-most-water/                                                                                                            
/// Author : yanming
/// Time   : 2019-05-19

/***
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

 The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
*/

#include <iostream>
#include <vector>
#include <cassert>

/// Two Pointers
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int maxArea(std::vector<int>& height) {
        assert(height.size() >= 2);

        int l = 0, r = height.size() - 1;
        int area = 0;
        while (l < r) {
            area = std::max(area, std::min(height[l], height[r]) * (r - l));
            if (height[l] < height[r])
                l++;
            else
                r--;
        }

        return area;
    }
};

int main() {

    std::vector<int> nums1 = {1, 1};
    std::vector<int> nums2 = {1,8,6,2,5,4,8,3,7};
    std::cout << Solution().maxArea(nums1) << std::endl;
    std::cout << Solution().maxArea(nums2) << std::endl; // 49
        
    return 0;
}