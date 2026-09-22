class Solution {
        public:
                int trap(vector<int>& height) {
                        int result = 0;
                        int n = height.size();
                        vector<int> left(n);
                        vector<int> right(n);

                        int max_left = 0;
                        for (int i = 0; i < n; i++) {
                                if (height[i] > max_left) {
                                        max_left = height[i];
                                }
                                left[i] = max_left;
                        }

                        int max_right = 0;
                        for (int i = n - 1; i >= 0; i--) {
                                if (height[i] > max_right) {
                                        max_right = height[i];
                                }
                                right[i] = max_right;
                        }

                        for (int i = 0; i < n; i++) {
                                result += min(left[i], right[i]) - height[i];
                        }

                        return result;
                }
};

/* Good solution but code can be shortened (shortened code above) */
class Solution {
        public:
                int trap(vector<int>& height) {
                        int result = 0;
                        int n = height.size();
                        vector<int> left(n);
                        vector<int> right(n);

                        int max_left = -1;
                        for (int i = 0; i < n; i++) {
                                if (height[i] > max_left) {
                                        max_left = height[i];
                                        left[i] = -1;
                                } else{
                                        left[i] = max_left;
                                }
                        }

                        int max_right = -1;
                        for (int i = n - 1; i >= 0; i--) {
                                if (height[i] > max_right) {
                                        max_right = height[i];
                                        right[i] = -1;
                                } else {
                                        right[i] = max_right;
                                }
                        }

                        for (int i = 0; i < n; i++) {
                                if (left[i] != -1 && right[i] != -1) {
                                        result += min(left[i], right[i]) - height[i];
                                }
                        }

                        return result;
                }
};
