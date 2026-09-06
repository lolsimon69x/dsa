#include <iostream>
#include <vector>

class Solution {
        public:
                int pivotIndex(vector<int>& nums) {
                        int n = nums.size();
                        vector<long long> ps(nums.size() + 1);

                        for (int i = 0; i < n; i++) {
                                ps[i + 1] = nums[i] + ps[i];
                        }

                        for (int i = 0; i < n; i++) {
                                if (ps[i] - ps[0] == ps[n] - ps[i + 1])
                                        return i;
                        }

                        return -1;
                }
};
