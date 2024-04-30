// Leetcode 1915 (medium)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<int> count(1024, 0);
        count[0] = 1;
        long long ans = 0;
        int mask = 0;

        for (char ch : word) {
            int index = ch - 'a';
            mask ^= 1 << index;
            ans += count[mask];
            for (int i = 0; i < 10; i++) {
                ans += count[mask ^ (1 << i)];
            }
            count[mask]++;
        }

        return ans;
    }
};

int main() {
    Solution sol;
    string word = "aabb";
    cout << "The number of wonderful substrings in '" << word << "' is: " << sol.wonderfulSubstrings(word) << endl;
    return 0;
}