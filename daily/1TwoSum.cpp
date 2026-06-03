// Problem 1: Two Sum (https://leetcode.com/problems/two-sum)
// Date: 6/3/2026
//
// Solution Method: Since we are allowed to assume that each input has exactly one solution, we can end our program the moment a solution is found. While we could use a double for loop to check if any proceeding elements from a value add to our target, this is inefficient. Rather, we can use a hashmap to look up the value as a key that will add to our target, which would be an O(1) operation (same logic, just a bit faster in the searching for second component part). The value for each key will be the index, which is what we need to output at the end.

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         unordered_map<int, int> values;

         for (int i = 0; i < nums.size(); i++) {
            int desired = target - nums[i];
            if (values.count(desired)) {
                return {i, values[desired]};
            }
            values.insert({nums[i], i});
         }
        
         return {0, 0};
    }
};
