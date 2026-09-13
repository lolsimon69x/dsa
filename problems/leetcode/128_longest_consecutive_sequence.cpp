class Solution {
        public:
                int longestConsecutive(vector<int>& nums) {
                        // WILL DO IT AFTER SOME TIME 
                        // BORED NOW
                }
};

/// BETTER BRUTE APPROACH /// (just needed a hint that we can sort() the array nums)
class Solution {
        public:
                int longestConsecutive(vector<int>& nums) {
                        int longestcons = 1;
                        int n = nums.size();
                        if (n == 0) {
                                return 0;
                        }

                        // sort array
                        sort(nums.begin(), nums.end());

                        int currentcons = 1;
                        for (int i = 0; i < n - 1; i++) {
                                if (nums[i + 1] != nums[i]) {
                                        if (nums[i + 1] == nums[i] + 1) {
                                                currentcons++;
                                        }

                                        else {
                                                longestcons = max(currentcons, longestcons);
                                                currentcons = 1;
                                        }
                                }
                        }

                        return max(longestcons, currentcons);
                }
};




/// BRUTE FORCE APPROACH /// (couldn't think of this myself)
class Solution {
        private:
                bool lc(vector<int>& nums, int target) {
                        for (int num : nums) {
                                if (num == target) {
                                        return true;
                                }
                        }

                        return false;
                }

        public:
                int longestConsecutive(vector<int>& nums) {
                        int longestcons = 0;

                        for (int num : nums) {
                                int currentcons = 1;
                                while (lc(nums, num + 1)) {
                                        num++;
                                        currentcons++;
                                }

                                longestcons = max(currentcons, longestcons);
                        }

                        return longestcons;
                }
};
