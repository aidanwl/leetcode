#include <iostream>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxHeight = 0;
        int left = 0;
        int right = heights.size() - 1;

        while (left < right) {
            int currentHeight = min(heights[left], heights[right]) * (right - left);
            maxHeight = currentHeight > maxHeight ? currentHeight : maxHeight;
            
            if (heights[left] > heights[right]) {
                right--;
            }
            else {
                left++;
            }
        }

        return maxHeight;
    }
};

