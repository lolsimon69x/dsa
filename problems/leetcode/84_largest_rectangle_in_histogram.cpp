class Solution {
        public:
                int largestRectangleArea(vector<int>& heights) {
                        int n = heights.size();
                        vector<int> left(n), right(n);
                        stack<int> st;

                        /* Nearest smaller to Left */
                        for (int i = 0; i < n; i++) {
                                while (!st.empty() && heights[st.top()] >= heights[i]) {
                                        st.pop();
                                }
                                left[i] = st.empty() ? -1 : st.top();
                                st.push(i);
                        }

                        /* clear stack */
                        while (!st.empty()) {
                                st.pop();
                        }

                        /* Nearest Smaller to Right */
                        for (int i = n - 1; i >= 0; i--) {
                                while (!st.empty() && heights[st.top()] >= heights[i]) {
                                        st.pop();
                                }
                                right[i] = st.empty() ? n : st.top();
                                st.push(i);
                        }

                        /* Calculate Max Area */
                        int area = 0;
                        for (int i = 0; i < n; i++) {
                                int width = right[i] - left[i] - 1;
                                area = max(area, heights[i] * width);
                        }

                        return area;
                }
};
