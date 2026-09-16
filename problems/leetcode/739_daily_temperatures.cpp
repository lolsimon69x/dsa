// Used Monotonic Stack (cool ass technique)

class Solution {
        public:
                vector<int> dailyTemperatures(vector<int>& temperatures) {
                        int n = temperatures.size();
                        stack<int> st;
                        vector<int> result(n);

                        for (int i = 0; i < n; i++) {
                                while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                                        int idx = st.top(); st.pop();
                                        result[idx] = i - idx;
                                }
                                st.push(i);
                        }

                        return result;
                }
};

/* MY SOLUTION (TIME LIMIT EXCEEDED) (47/48 TEST CASES PASSED)
 
class Solution {
        public:
                vector<int> dailyTemperatures(vector<int>& temperatures) {
                        int n = temperatures.size();
                        vector<int> result(n);

                        for (int i = 0; i < n; i++) {
                                int idx = i + 1;
                                while (idx  < n) {
                                        if (temperatures[i] < temperatures[idx]) {
                                                result[i] = abs(i - idx);
                                                break;
                                        }
                                        ++idx;
                                }
                        }

                        return result;
                }
};

