class Solution {
        public:
                int minEatingSpeed(vector<int>& piles, int h) {
                        int n = piles.size();
                        int max_e = *max_element(piles.begin(), piles.end());
                        int result;

                        int low = 1, high = max_e;
                        while (low <= high) {
                                long long hours = 0;

                                int mid = low + (high - low) / 2;
                                for (int i = 0; i < n; i++) {
                                        if (piles[i] % mid == 0) {
                                                hours += piles[i] / mid;
                                        } else {
                                                hours += piles[i] / mid + 1;
                                        }
                                }
                                if (hours <= h) {
                                        high = mid - 1;
                                        result = mid;
                                } else {
                                        low = mid + 1;
                                }
                        }

                        return result;
                }
};
