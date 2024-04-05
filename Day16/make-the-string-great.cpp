// Leetcode 1544

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string makeGood(string s) {
        stack<char> x;

        for (char c : s) {
            if (!x.empty() && abs(c - x.top()) == 32) {
                x.pop();
            } else {
                x.push(c);
            }
        }

        string ans;
        while (!x.empty()) {
            ans = x.top() + ans;
            x.pop();
        }

        return ans;
    }
};

int main() {
    Solution solution;

    // Test cases
    string input1 = "leEeetcode";
    string input2 = "abBAcC";
    string input3 = "s";
    
    cout << "Result for input '" << input1 << "': " << solution.makeGood(input1) << endl;
    cout << "Result for input '" << input2 << "': " << solution.makeGood(input2) << endl;
    cout << "Result for input '" << input3 << "': " << solution.makeGood(input3) << endl;

    return 0;
}
