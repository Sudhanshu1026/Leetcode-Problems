class Solution {
public:

bool check(int num, vector<vector<char>>& board, int i, int j) {
    char c = '0' + num;

    // Check For same Row
    for (int col = 0; col < 9; col++) {
        if (board[i][col] == c)
            return false;
    }

    // Check For same Column
    for (int row = 0; row < 9; row++) {
        if (board[row][j] == c)
            return false;
    }

    // Check For same Box (3x3)
    int row = (i / 3) * 3, col = (j / 3) * 3;
    for (int a = row; a < row + 3; a++) {
        for (int b = col; b < col + 3; b++) {
            if (board[a][b] == c)
                return false;
        }
    }

    return true;
}

bool find(int i, int j, vector<vector<char>>& board) {
    // Base Condition
    if (i == 9)
        return true;

    if (j == 9)
        return find(i + 1, 0, board);

    if (board[i][j] != '.')
        return find(i, j + 1, board);

   
    for (int num = 1; num <= 9; num++) {
        if (check(num, board, i, j)) {
            board[i][j] = '0' + num;

            if (find(i, j + 1, board))
                return true;
            board[i][j] = '.';
        }
    }

    return false;
}

void solveSudoku(vector<vector<char>>& board) {
    find(0, 0, board);
}
};
