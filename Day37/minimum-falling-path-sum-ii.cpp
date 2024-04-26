// Leetcode 1289
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, numeric_limits<int>::max()));

        for (int j = 0; j < n; ++j) {
            dp[0][j] = grid[0][j];
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (j != k) {
                        dp[i][j] = min(dp[i][j], grid[i][j] + dp[i - 1][k]);
                    }
                }
            }
        }

        int minSum = numeric_limits<int>::max();
        for (int j = 0; j < n; ++j) {
            minSum = min(minSum, dp[n - 1][j]);
        }

        return minSum;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int result = solution.minFallingPathSum(grid);
    cout << "Minimum falling path sum: " << result << endl;

    return 0;
}