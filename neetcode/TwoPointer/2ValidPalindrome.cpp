#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string newS;
        int length = 0;

        for (char c: s) {
            if (isalpha(c)) {
                newS += tolower(c);
                length++;
            }
            else if (isdigit(c)) {
                newS += c;
                length++;
            }
        }

        for (int i = 0, j = length - 1; i <= j; i++, j--) {
            if (newS[i] != newS[j]) {
                return false;
            }
        }

        return true;
    }
};

