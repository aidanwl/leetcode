#include <iostream>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> leftMax(height.size());
        vector<int> rightMax(height.size());
        
        int leftCMax = height[0];
        leftMax[0] = leftCMax;
        for (int i = 1; i < height.size(); i++) {
            leftCMax = leftCMax > height[i] ? leftCMax : height[i];
            leftMax[i] = leftCMax;
        }
        
        int rightCMax = height[height.size() - 1];
        rightMax[height.size() - 1] = rightCMax;
        for (int i = height.size() - 2; i >= 0; i--) {
            rightCMax = rightCMax > height[i] ? rightCMax : height[i];
            rightMax[i] = rightCMax;
        }

        int solution = 0;

        for (int i = 0; i < height.size(); i++) {
            solution += min(leftMax[i], rightMax[i]) - height[i];
        }

        return solution;
    }
};

