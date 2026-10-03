class Solution {
        public:
                vector<int> maxSlidingWindow(vector<int>& nums, int k) {
                        vector<int> res;
                        deque<int> dq;
                        int right = 0;

                        while (right < nums.size()) {
                                if (!dq.empty() && dq.front() <= right - k) {
                                        dq.pop_front();
                                }

                                while (!dq.empty() && nums[dq.back()] <= nums[right]) {
                                        dq.pop_back();
                                }

                                dq.push_back(right);

                                if (right >= k - 1) {
                                        res.push_back(nums[dq.front()]);
                                }

                                right++;
                        }

                        return res;
                }
};

/* MY SOLUTION (time limit exceeded)
class Solution {
        public:
                vector<int> maxSlidingWindow(vector<int>& nums, int k) {
                        vector<int> res;
                        int left = 0, right = 0;

                        while (right < nums.size()) {
                                int windowSize = right - left + 1;
                                if (windowSize < k) {
                                        right++;
                                        continue;
                                }
                                int m = *max_element(nums.begin() + left, nums.begin() + right + 1);
                                res.push_back(m);

                                left++;
                                right++;
                        }

                        return res;
                }
};
