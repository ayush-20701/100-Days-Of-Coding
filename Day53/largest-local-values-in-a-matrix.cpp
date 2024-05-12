// Leetcode 2373 (Easy)
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int m = n-2;
        vector<vector<int>> maxLocal(m, vector<int>(m));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {
                int x = i + 1;
                int y = j + 1;
                maxLocal[i][j] = findLargest(x, y, grid);
            }
        }
        return maxLocal;
    }
    int findLargest(int x, int y, vector<vector<int>>& grid){
        int large = grid[x][y];
        for(int i = x-1; i <= x+1; i++) {
            for(int j = y-1; j <= y+1; j++) {
                if(grid[i][j] > large)
                    large = grid[i][j];
            }
        }
        return large;
    }
};