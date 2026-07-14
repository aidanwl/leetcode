#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();
        vector<int> solution(length);
        int left = 1;
        int right = 1;

        for (int i = 0; i < length; i++) {
            solution[i] = left;
            left *= nums[i];
        }

        for (int i = length - 1; i >= 0; i--) {
            solution[i] *= right;
            right *= nums[i];
        }

        return solution;
    }
};
