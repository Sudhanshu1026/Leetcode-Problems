class Spreadsheet {
private:
    vector<vector<int>> grid; // rows x 26
    int rows;

    // Convert "A1" -> (rowIdx, colIdx)
    pair<int,int> parseCell(const string &cell) {
        char colChar = cell[0];
        int col = colChar - 'A'; 
        int row = stoi(cell.substr(1)) - 1; 
        return {row, col};
    }

    // Get value of token (either number or cell reference)
    int getTokenValue(const string &token) {
        if (isdigit(token[0])) {
            return stoi(token);
        } else {
            auto [r, c] = parseCell(token);
            return grid[r][c];
        }
    }

public:
    Spreadsheet(int rows) {
        this->rows = rows;
        grid.assign(rows, vector<int>(26, 0));
    }

    void setCell(string cell, int value) {
        auto [r, c] = parseCell(cell);
        grid[r][c] = value;
    }

    void resetCell(string cell) {
        auto [r, c] = parseCell(cell);
        grid[r][c] = 0;
    }

    int getValue(string formula) {
        formula = formula.substr(1); // remove '='
        int plusPos = formula.find('+');
        string left = formula.substr(0, plusPos);
        string right = formula.substr(plusPos + 1);
        return getTokenValue(left) + getTokenValue(right);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */