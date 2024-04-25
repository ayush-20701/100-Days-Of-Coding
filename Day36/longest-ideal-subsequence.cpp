// Leetcode 2370
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26, 0);
        int ans = 1;

        for(int i = 0; i < s.length(); ++i) {
            int ele = s[i] - 'a';

            for(int j = ele; j >= 0 && j >= ele - k; --j) {
                dp[ele] = max(dp[ele], dp[j] + 1);
            }

            for(int j = ele + 1; j < 26 && j <= ele + k; ++j) {
                dp[ele] = max(dp[ele], dp[j] + 1);
            }

            ans = max(ans, dp[ele]);
        }

        return ans;
    }
};

int main() {
    Solution solution;
    string input = "eduktdb";
    int k = 15;
    int result = solution.longestIdealString(input, k);
    cout << "Longest ideal string length: " << result << endl;
    return 0;
}