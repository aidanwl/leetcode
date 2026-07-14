#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> values;

        // Building the hashmap for the correct number of values
        for (int i = 0; i < s.size(); i++) {
            if (values.count(s[i])) {
                values[s[i]] += 1;
            }
            else {
                values[s[i]] = 1;
            }
        }
        
        // Checking the values to see if they match, remove values and check at end to see if map is empty
        for (int i = 0; i < t.size(); i++) {
            if (values.count(t[i])) {
                values[t[i]] -= 1;
                if (values[t[i]] == 0) {
                    values.erase(t[i]);
                }
            }
            else {
                return false;
            }
        }

        return values.empty();
    }
};

