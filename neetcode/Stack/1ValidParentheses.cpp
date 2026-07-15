#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> prio;
        
        if (s.size() % 2 != 0) {
            return false;
        }

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '[' || s[i] == '{' || s[i] == '(') {
                prio.push(s[i]);
            }
            else {
                if (prio.empty()) return false;
                if (s[i] == ']' && prio.top() != '[') return false;
                if (s[i] == '}' && prio.top() != '{') return false;
                if (s[i] == ')' && prio.top() != '(') return false;
                prio.pop();
            }
        }

        if (!prio.empty()) return false;

        return true;
    }
};



