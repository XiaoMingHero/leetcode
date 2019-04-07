//
// Created by xuyanming on 2019-04-07.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
void printVec(const vector<int>& twoSum);


/**
 *  hash table
 *  time O(n)
 *  space O(n)
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> record;
        for (int i = 0; i < nums.size(); ++i) {
            record[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); ++i) {
            unordered_map<int, int>::iterator iter = record.find(target - nums[i]);
            if (iter != record.end() && i != iter->second) {
                int res[] = {i, iter->second};
                return vector<int>(res, res + 2);
            }
        }

        printf("has no result \n");
    }
};

void printVec(const vector<int>& twoSum) {
    for (int e : twoSum)
        std::cout << e << " ";
    cout << endl;
}

int main() {

    const int nums[] = {0, 3, 4, 0};
    std::vector<int> num_vec(nums, nums + sizeof(nums));
    int target = 0;
    printVec(Solution().twoSum(num_vec, target));

    return 0;
}