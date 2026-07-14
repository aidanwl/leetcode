#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> grouped;
        int latestPlace = 0;
        unordered_map<string, int> sortedStrings;
        for (int i = 0; i < strs.size(); i++) {
            string indSort = strs[i];
            sort(indSort.begin(), indSort.end());
            if (sortedStrings.count(indSort)) {
                grouped[sortedStrings[indSort]].push_back(strs[i]);
            }
            else {
                sortedStrings[indSort] = latestPlace;
                grouped.push_back({strs[i]});
                latestPlace++;
            }
        }

        return grouped;
    }
};

