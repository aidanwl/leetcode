#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int pos1 = 0;
        int pos2 = numbers.size() - 1;
        int sum = numbers[pos1] + numbers[pos2];

        while (sum != target) {
            sum = numbers[pos1] + numbers[pos2];

            if (sum > target) {
                pos2--;
            }

            else if (sum < target) {
                pos1++;
            }
        }

        return {pos1, pos2};
    }
};

