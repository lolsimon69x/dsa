class Solution {
        public:
                int lengthOfLongestSubstring(string s) {
                        int n = s.size();
                        int left = 0, right = 0, res = 0;
                        map<char, int> m;

                        while (right < n) {
                                m[s[right]]++;
                                int windowSize = right - left + 1;

                                if (m.size() == windowSize) {
                                        res = max(res, windowSize);
                                        right++;
                                }
                                else {
                                        m[s[left]]--;
                                        if (m[s[left]] == 0) {
                                                m.erase(s[left]);
                                        }
                                        left++;
                                        m[s[right]]--;
                                }
                        }

                        return res;
                }
};
