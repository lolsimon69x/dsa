// What the fuck was this question
// REVIEW NEEDED

class Solution {
        public:
                int carFleet(int target, vector<int>& position, vector<int>& speed) {
                        int n = position.size();
                        map<int, double> car;

                        for (int i = 0; i < n; i++) {
                                car[-position[i]] = (double)(target - position[i]) / speed[i];
                        }

                        int fleet = 0;
                        double current_time = -1;
                        for (auto& [pos, time]  : car) {
                                if (time > current_time) {
                                        current_time = time;
                                        fleet++;
                                }
                        }

                        return fleet;
                }
};
