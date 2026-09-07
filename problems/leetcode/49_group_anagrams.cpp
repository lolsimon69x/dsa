#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/* After seeing the solution */
class Solution {
        public:
                vector<vector<string>> groupAnagrams(vector<string>& strs) {
                        unordered_map<string, vector<string>> groups;
                        vector<vector<string>> result;

                        for (string &s : strs) {
                                string key = s;
                                sort(key.begin(), key.end());
                                groups[key].push_back(s);
                        }

                        for (auto& [key, group] : groups) {
                                result.push_back(group);
                        }

                        return result;
                }
};

/* MY SOLUTION 


class Solution {
        public:
                vector<vector<string>> groupAnagrams(vector<string>& strs) {
                        int n = strs.size();
                        vector<bool> seenVal(n, false);

                        vector<vector<string>> result;
                        for (int i = 0; i < n; i++) {
                                if (seenVal[i] == true) {
                                        continue;
                                }

                                string str = strs[i];
                                sort(str.begin(), str.end());

                                vector<string> temp;
                                for (int j = i; j < n; j++) {
                                        string jstr = strs[j];
                                        sort(jstr.begin(), jstr.end());

                                        if (str == jstr) {
                                                temp.push_back(strs[j]);
                                                seenVal[j] = true;
                                        }
                                }

                                result.push_back(temp);
                        }

                        return result;
                }
};
*/
