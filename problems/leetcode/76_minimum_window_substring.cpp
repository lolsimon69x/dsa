class Solution {
        public:
                string minWindow(string s, string t) {

                        int resl = 0, resr = s.size();
                        int left = 0, right = 0;
                        unordered_map<char, int> ms;
                        unordered_map<char, int> mt;

                        for (char& key : t) {
                                mt[key]++;
                                ms[key] = 0;
                        }

                        int need = mt.size(), have = 0;
                        while (right < s.size()) {
                                if (ms.contains(s[right])) {
                                        ms[s[right]]++;
                                        if (ms[s[right]] == mt[s[right]]) {
                                                have++;
                                        }
                                }

                                while (have == need) {
                                        if (right - left < resr - resl) {
                                                resr = right;
                                                resl = left;
                                        }
                                        if (ms.contains(s[left])) {
                                                ms[s[left]]--;
                                                if (ms[s[left]] < mt[s[left]]) {
                                                        have--;
                                                }
                                        }
                                        left++;
                                }
                                right++;
                        }

                        if (resr == s.size()) return "";
                        return s.substr(resl, resr - resl + 1);
                }
};
