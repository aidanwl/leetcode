#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seenNums;
        for (int i = 0; i < nums.size(); i++) {
            int desired = target - nums[i];
            if (seenNums.count(desired)) {
                return {seenNums[desired], i};
            }
            seenNums[nums[i]] = i;
        }
        return {0, 0};
    }
};
