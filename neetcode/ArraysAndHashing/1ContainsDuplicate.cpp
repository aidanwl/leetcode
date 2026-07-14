#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> seenList;
        for (int i = 0; i < nums.size(); i++) {
            if (seenList.count(nums[i])) {
                return true;
            }
            seenList[nums[i]] = 1;
        }

        return false;
    }
};


