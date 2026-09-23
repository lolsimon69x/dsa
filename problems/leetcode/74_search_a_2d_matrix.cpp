class Solution {
        public:
                bool searchMatrix(vector<vector<int>>& matrix, int target) {
                        int rows = matrix.size();
                        int cols = matrix[0].size();
                        int n = rows * cols;

                        int low = 0, high = n - 1;
                        while (low <= high) {
                                int mid = low + (high - low) / 2;
                                int row = mid / cols;
                                int col = mid % cols;

                                if (target == matrix[row][col]) {
                                        return true;
                                } else if (target < matrix[row][col]) {
                                        high = mid - 1;
                                } else {
                                        low = mid + 1;
                                }
                        }

                        return false;
                }
};
