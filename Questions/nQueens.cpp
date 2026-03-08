class Solution {
private:
    bool isSafe(int row, int col, vector<string> &board, int n){
        // we only check queens present on the left NOT right because we havent inserted queens to the right yet
        // check => left, upper diagonal, lower diagonal

        // preserve the row and col
        int tempRow = row;
        int tempCol = col;

        // check upper diagonal
        while(row >= 0 && col >= 0){
            if(board[row][col] == 'Q') return false; // queen is present
            row--;
            col--;
        }

        row = tempRow;
        col = tempCol;

        // check left
        while(col >= 0){
            if(board[row][col] == 'Q') return false;
            col--;
        }

        col = tempCol;

        // check lower diagonal
        while(row < n && col >= 0){
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }

        return true;
    }

    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){
        if(col == n){ // all columns filled
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++){
            if(isSafe(row, col, board, n)){ // if its safe to place queen
                board[row][col] = 'Q'; // place the queen
                solve(col + 1, board, ans, n); // explore 
                // backtrack
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');

        for(int i = 0; i < n; i++){ // initially chess board is empty ('.')
            board[i] = s;
        }

        solve(0, board, ans, n); // col, current board, all possible boards, n columns
        return ans;
    }
};
