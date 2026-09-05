// Not complete
#include <iostream>
#include <vector>

class Solution {
public:
    int numOfsub;

    int prefixSum(int left, int right) {
        return pnum[right + 1] - pnum[left];
    }

    int subarraySum(vector<int>& nums, int k) {

        vector<long long> pnum(nums.size() * nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (pnum[j + 1] - pnum[i] == k) {
                    numOfsub++;
                }
            }
        }

        return numOfsub;
    }
};
