class Solution {
        public:
                int maxArea(vector<int>& height) {
                        int maxArea = -1;
                        int n = height.size();

                        int left = 0, right = n - 1;
                        while (left < right) {
                                int cArea = min(height[left], height[right]) * (right - left);
                                maxArea = max(cArea, maxArea);

                                if (height[left] < height[right]) {
                                        left++;
                                } else {
                                        right--;
                                }
                        }

                        return maxArea;
                }
};
