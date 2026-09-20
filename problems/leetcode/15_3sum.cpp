class Solution {
        public:
                vector<vector<int>> threeSum(vector<int>& nums) {
                        int n = nums.size();
                        vector<vector<int>> result;

                        sort(nums.begin(), nums.end());

                        for (int i = 0; i < n - 2; i++) {
                                if (i > 0 && nums[i - 1] == nums[i]) {
                                        continue;
                                }

                                int target = -nums[i];
                                int low = i + 1;
                                int high = n - 1;

                                while (low < high) {
                                        if (nums[low] + nums[high] == target) {
                                                result.push_back({nums[i], nums[low], nums[high]});
                                                low++;
                                                high--;
                                                while (nums[low] == nums[low - 1] && low < high) {
                                                        low++;
                                                }
                                        } else if (nums[low] + nums[high] < target) {
                                                low++;
                                        } else {
                                                high--;
                                        }
                                }
                        }

                        return result;
                }
};
