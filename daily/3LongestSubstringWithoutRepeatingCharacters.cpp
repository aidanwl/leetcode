// Problem 3: Longest Substring Without Repeating Characters (https://leetcode.com/problems/longest-substring-without-repeating-characters)
// Date: 6/8/2026
//
// Solution Method: Use a hashmap to record all the letters that currently appear in the stirng. This will be used within each "substring" to check if a letter has been repeated yet. A second hashmap is not required, and we can simply check for the length of each "substring" as we go along and update it until the end. The last step should be comparing the saved length to the current length and outputting whichever one is greater.
//
// Failure 1: Sliding window loses length for things like dvdf, where it can be split dv df for 2 (incorrect) instead of d vdf for 3 (correct). A slow way to fix this would be to have an additional for loop that encases the current algorithm that removes the first character. However, a better solution would be to actually use the key value of the hashmap. By storing the index, we are able to see the point at which we can "jump back to" to continue checking in the most optimal way. However, if we have multiple "jump backs," we can get into slower algos and infinite loops, so to solve this we create another variable to keep track of the "minimum start position," which fixes that edge case.
//
// Failure 2: Sliding window not implemented correctly. We are still reprocessing information which makes it inefficient. Instead, we can simply adjust "right" and "left" variables to calculate the length. the right variable is given by i, and the minStart can be repurposed into the left. The final length calculation should simply use these variables. 

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> alphabet;
        
        int left = 0;
        int right = 0;
        int maxLength = 0;

        for (right = 0; right < s.size(); right++) {
            if (alphabet.count(s[right])) {
                left = (alphabet[s[right]] + 1 > left) ? alphabet[s[right]] + 1 : left; 
            }

            alphabet[s[right]] = right;
            maxLength = (maxLength > (right - left + 1)) ? maxLength : (right - left + 1);
        }

        return maxLength;
    }
};


