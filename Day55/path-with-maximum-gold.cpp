// Leetcode 1219 (Medium) 

class Solution {
public:
    vector<int> row = {1, -1, 0, 0};
    vector<int> col = {0, 0, -1, 1};
    int ans = 0;

    int solve(vector<vector<int>>& grid, int x, int y, int n, int m) {
        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0) return 0;
        
        int temp = grid[x][y];
        grid[x][y] = 0;
        int localMaxGold = temp;

        for (int i = 0; i < 4; i++) {
            int newX = x + row[i];
            int newY = y + col[i];
            localMaxGold = max(localMaxGold, temp + solve(grid, newX, newY, n, m));
        }

        grid[x][y] = temp;
        return localMaxGold;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) {
                    ans = max(ans, solve(grid, i, j, n, m));
                }
            }
        }

        return ans;
    }
};