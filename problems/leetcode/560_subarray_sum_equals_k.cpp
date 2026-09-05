// Not complete
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();

        vector<long long> pnum(n + 1);

        for (int i = 0; i < n; ++i) {
            pnum[i + 1] = nums[i] + pnum[i];
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (pnum[j + 1] - pnum[i] == k)
                    ans++;
            }
        }

        return ans;
    }
};
