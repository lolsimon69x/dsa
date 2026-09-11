// NEEDED HINT TO SOLVE
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
        public:
                vector<int> topKFrequent(vector<int>& nums, int k) {
                        vector<int> result;
                        int n = nums.size();
                        unordered_map<int, int> dict;

                        for (int i = 0; i < n; i++) {
                                int key = nums[i];
                                dict[key]++;
                        }

                        vector<vector<int>> bucket(n + 1);

                        for (auto& [key, value] : dict) {
                                bucket[value].push_back(key);
                        }

                        int index = 0;
                        for (int i = n; i >= 0; i--) {
                                if (!bucket[i].empty()) {
                                        for (int& val : bucket[i]) {
                                                result.push_back(val);
                                                index++;
                                                if (index == k) return result;
                                        }
                                }
                        }

                        return result;
                }

};
