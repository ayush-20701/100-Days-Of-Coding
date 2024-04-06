// Leetcode 1249

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> x;
        string ans = "";
        int left = 0, right = 0;
        for (char c : s) {

            if (c == '(') left++;
            else if (c == ')') right++;

            if (right > left) {
                right--;
                continue;
            }
            else
                x.push(c);
        }

        while (!x.empty()) {
            char temp = x.top();
            x.pop();

            if (left > right && temp == '(') left--;
            else ans += temp;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution solution;

    // Test case
    string input = "lee(t(c)o)de)";

    string result = solution.minRemoveToMakeValid(input);
    cout << "Modified string: " << result << endl;

    return 0;
}
