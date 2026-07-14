#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> numsTwo;

        int largestNumber = 0;

        for (int i = 0; i < nums.size(); i++) {
            largestNumber = nums[i] > largestNumber ? nums[i] : largestNumber;
            numsTwo.insert(nums[i]);
        }

        int largest = 0;

        for (int i = 0; i < nums.size(); i++) {
            auto it = numsTwo.find(nums[i] - 1);
            if (it == numsTwo.end()) {
                int temp = 1;
                int current = nums[i] + 1;
                while (numsTwo.find(current) != numsTwo.end()) {
                    temp++;
                    current++;
                }
                largest = largest > temp ? largest : temp;
                temp = 1;
            }
        }

        return largest;
    }
};

