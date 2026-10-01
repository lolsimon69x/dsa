class Solution {
        public:
                bool checkInclusion(string s1, string s2) {
                        unordered_map<char, int> m1;
                        unordered_map<char, int> m2;
                        int windowSize = s1.size();
                        int left = 0, right = 0, res = 0;

                        for (int i = 0; i < s1.size(); i++) {
                                m1[s1[i]]++;
                        }

                        while (right < s2.size()) {
                                ++m2[s2[right]];

                                if (right - left + 1 == windowSize) {
                                        if (m1 == m2) {
                                                return true;
                                        }
                                        else {
                                                --m2[s2[left]];
                                                if (m2[s2[left]] == 0) {
                                                        m2.erase(s2[left]);
                                                }
                                                ++right;
                                                ++left;
                                        }
                                }
                                else {
                                        ++right;
                                }
                        }

                        return false;
                }
};
