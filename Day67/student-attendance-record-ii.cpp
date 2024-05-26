// Leetcode 552 (Hard) - DP
class Solution {
public:
    int checkRecord(int n) {
        const int MOD = 1000000007;
        
        // dp[i][j][k] will be the number of sequences of length i with j 'A's and ending with k consecutive 'L's
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        
        // Base case: one empty sequence
        dp[0][0][0] = 1;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= 1; ++j) {
                for (int k = 0; k <= 2; ++k) {
                    // Add 'P' (it doesn't affect the count of 'A's or 'L's)
                    dp[i][j][0] = (dp[i][j][0] + dp[i-1][j][k]) % MOD;
                    
                    // Add 'A' (only if there is no 'A' yet)
                    if (j > 0) {
                        dp[i][j][0] = (dp[i][j][0] + dp[i-1][j-1][k]) % MOD;
                    }
                    
                    // Add 'L' (only if the streak of 'L's is less than 2)
                    if (k > 0) {
                        dp[i][j][k] = (dp[i][j][k] + dp[i-1][j][k-1]) % MOD;
                    }
                }
            }
        }
        
        int ans = 0;
        
        // Sum up all valid sequences of length n
        for (int j = 0; j <= 1; ++j) {
            for (int k = 0; k <= 2; ++k) {
                ans = (ans + dp[n][j][k]) % MOD;
            }
        }
        
        return ans;
    }    
};