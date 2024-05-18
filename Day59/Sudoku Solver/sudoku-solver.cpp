// Leetcode 37 (Hard)

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    bool solve(vector<vector<char>>& board) {
        int n = board.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                if(board[i][j] == '.') {
                    for(int val = 1; val <= 9; val++){
                        char charVal = static_cast<char>(val + '0');
                        if(isSafe(board, i, j, charVal)) {
                            board[i][j] = charVal;
                            bool nextSolValid = solve(board);

                            if(nextSolValid) {
                                return true;
                            }
                            else{
                                //backtrack
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isSafe(vector<vector<char>>& board, int row, int col, char val) {
        //check for same row
        for(int i = 0; i < 9; i++) {
            if(board[row][i] == val) return false;
        }
        //check for same column
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == val) return false;
        }
        //check for same 3x3 matrix
        for(int i = 0; i < 9; i++) {
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val) return false;
        }
        return true;
    }
};