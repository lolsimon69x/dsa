// couldn't do it myself (review needed)

#include <vector>
#include <unordered_set>

class Solution {
        public:
                bool isValidSudoku(vector<vector<char>>& board) {
                        // 9 hash sets for each row, column, box
                        unordered_set<char> rows[9];
                        unordered_set<char> cols[9];
                        unordered_set<char> boxes[9];

                        for (int r = 0; r < 9; r++) {
                                for (int c = 0; c < 9; c++) {
                                        if (board[r][c] == '.') {
                                                continue;
                                        }

                                        char value = board[r][c];
                                        int boxIndex = (r / 3) * 3 + (c / 3);

                                        if (rows[r].count(value) || cols[c].count(value)
                                                        || boxes[boxIndex].count(value)) {
                                                return false;
                                        }

                                        rows[r].insert(value);
                                        cols[c].insert(value);
                                        boxes[boxIndex].insert(value);
                                }
                        }
                        return true;
                }
};
