#include <iostream>
#include <algorithms>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> solution;

        for (int i = 0; i < nums.size() - 1; i++) {
            
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;
            int target = 1;
            while (left < right) {
                target = nums[i] + nums[left] + nums[right];
                
                if (target == 0) {
                    solution.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }

                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }


                }
                else if (target > 0) {
                    right--;
                }
                else if (target < 0) {
                    left++;
                }
            }
        }

        return solution;
    }
};

