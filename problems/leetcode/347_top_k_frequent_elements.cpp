#include <vector>

class Solution {
        public:
                vector<int> topKFrequent(vector<int>& nums, int k) {
                        vector<int> result(k);
                        int n = nums.size();
                        unordered_map<int, int> dict;

                        for (int i = 0; i < n; i++) {
                                int key = nums[i];
                                dict[key] += 1;
                        }


                        int freq1, freq2;
                        freq1 = freq2;
                        for (auto& [key, value] : dict) {
                                if (dict[key] > freq1) {
                                        freq2 = freq1;
                                        freq1 = dict[key];
                                }
                        }
};
