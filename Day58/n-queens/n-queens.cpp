// Leetcode 51 (Hard)
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> board(n, vector<string>(n,"."));
        vector<vector<string>> ans;

        solve(0, ans, board, n);
        return ans;
    }
    void solve(int col, vector<vector<string>> &ans, vector<vector<string>> &board, int n) {
        //base case
        if(col == n) {
            addSolution(ans, board, n);
            return;
        }

        for(int row = 0; row < n; row++) {
            if(isSafe(row, col, board, n)) {
                board[row][col] = "Q";
                solve(col+1, ans, board, n);
                board[row][col] = ".";
            }
        }
    }
    bool isSafe(int row, int col, vector<vector<string>> &board, int n) {
        int  x = row;
        int y = col;

        //check for same row
        while(y >= 0) {
            if(board[x][y] == "Q")  //because only index of col decrements in this direction
                return false;
            y--;
        }

        //check for left upper diagonal
        x = row;
        y = col;
        while(x >= 0 && y >= 0) {  //because index of row and col decrements in this direction
            if(board[x][y] == "Q")
                return false;
            x--;
            y--;
        }

        //check for left lower diagonal
        x = row;
        y = col;
        while(x < n && y >= 0) {  //because index of row increments and col decrements in this direction
            if(board[x][y] == "Q")
                return false;
            x++;
            y--;
        }
        return true;
    }
    void addSolution(vector<vector<string>> &ans, vector<vector<string>> &board, int n) {
        vector<string> temp;
        for(int i = 0; i < n; i++) {
            string str;
            for(int j = 0; j < n; j++) {
                str.push_back(board[i][j][0]);
            }
            temp.push_back(str);
        }
        ans.push_back(temp);
    }
};