// Leetcode 1614

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int count = 0, depth = 0;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                count++;
                depth = max(count, depth);
            }
            if(s[i] == ')') {
                count--;
            }
        }

        return depth;
    }
};

int main() {
    Solution solution;
    string input;
    
    cout << "Enter a string containing parentheses: ";
    getline(cin, input);

    int max_depth = solution.maxDepth(input);
    cout << "Maximum depth of parentheses: " << max_depth << endl;

    return 0;
}
