class Solution {
        public:
                int findDuplicate(vector<int>& nums) {
                        int n = nums.size() - 1;
                        vector<int> nm(n + 1, 0);

                        for (int i = 0; i < n + 1; i++) {
                                if (nm[nums[i]] == 0) {
                                        nm[nums[i]] = nums[i];
                                }
                                else {
                                        return nums[i];
                                }
                        }

                        return 0;
                }
};
