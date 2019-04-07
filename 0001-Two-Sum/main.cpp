//
// Created by 许晏铭 on 2019-04-07.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
void printVec(const vector<int>& twoSum);


/**
 *  brute force
 *  time O(n^2)
 *  space O(1)
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i)
            for (int j = i + 1; j < nums.size(); ++j)
                if (nums[i] + nums[j] == target) {
                    int res[] = {i, j};
                    return vector<int>(res, res + 2);
                }

        printf("has no result \n");
    }
};

void printVec(const vector<int>& twoSum) {
    for (int e : twoSum)
        std::cout << e << " ";
    cout << endl;
}

int main1() {

    const int nums[] = {0, 3, 4, 0};
    std::vector<int> num_vec(nums, nums + sizeof(nums));
    int target = 0;
    printVec(Solution().twoSum(num_vec, target));

    return 0;
}