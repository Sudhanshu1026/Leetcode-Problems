class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
private:
    bool solve(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') {
                    for (char d = '1'; d <= '9'; d++) {
                        if (isValid(board, r, c, d)) {
                            board[r][c] = d;
                            if (solve(board)) return true; // recursion
                            board[r][c] = '.'; // backtrack
                        }
                    }
                    return false; // no valid digit, backtrack
                }
            }
        }
        return true; // solved
    }

    bool isValid(vector<vector<char>>& board, int r, int c, char d) {
        for (int i = 0; i < 9; i++) {
            // check row and col
            if (board[r][i] == d || board[i][c] == d) return false;
            // check 3x3 box
            int boxRow = 3 * (r / 3) + i / 3;
            int boxCol = 3 * (c / 3) + i % 3;
            if (board[boxRow][boxCol] == d) return false;
        }
        return true;
    }
};
