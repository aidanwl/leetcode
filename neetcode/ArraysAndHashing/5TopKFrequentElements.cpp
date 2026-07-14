#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       // Create unordered_map
       unordered_map<int, int> frequency_map;

       for (int i = 0; i < nums.size(); i++) {
           if (frequency_map.count(nums[i])) {
               frequency_map[nums[i]] += 1;
           }
           else {
               frequency_map[nums[i]] = 1;
           }
       }
        
       // Create buckets with each frequency from lowest to highest
        
       int highestFrequency = 1;
       unordered_map<int, vector<int>> buckets;

       for (const auto& pair : frequency_map) {
            if (buckets.count(pair.second)) {
                buckets[pair.second].push_back(pair.first);
                highestFrequency = (pair.second > highestFrequency) ? pair.second : highestFrequency;
            }
            else {
                buckets[pair.second] = {pair.first};
                highestFrequency = (pair.second > highestFrequency) ? pair.second : highestFrequency;
            }
       }

       // Get the top K Frequent
        
       vector<int> topK;

       while (k > 0) {
           if (buckets.count(highestFrequency)) {
               topK.push_back(buckets[highestFrequency].back());
               k--;
               buckets[highestFrequency].pop_back();
               if (buckets[highestFrequency].empty()) {
                   buckets.erase(highestFrequency);
                   highestFrequency--;
               }
           }
           else {
               highestFrequency--;
           }
       }

       return topK;
    }
};

