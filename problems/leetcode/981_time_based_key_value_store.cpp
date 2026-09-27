class TimeMap {
        private:
                unordered_map<string, vector<pair<int, string>>> tmap;
        public:
                TimeMap() {
                }

                void set(string key, string value, int timestamp) {
                        tmap[key].push_back({timestamp, value});
                }

                string get(string key, int timestamp) {
                        int n = tmap[key].size();
                        vector<pair<int, string>>& vec = tmap[key];

                        int low = 0, high = n - 1;
                        string result = "";

                        while (low <= high) {
                                int mid = low + (high - low) / 2;

                                if (vec[mid].first == timestamp) {
                                        return vec[mid].second;
                                } else if (vec[mid].first > timestamp) {
                                        high = mid - 1;
                                } else {
                                        result = vec[mid].second;
                                        low = mid + 1;
                                }
                        }

                        return result;
                }
};
