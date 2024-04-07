#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int left = 0, right = 0;

        for(char c : s) {
            if(c == '(') {
                left++;
                right++;
            }
            else if(c == ')') {
                left--;
                right--;
            }
            else {
                left--;
                right++;
            }
            if(right < 0) return false;
            if(left < 0) left = 0;
        }
        return left == 0;
    }
};

int main() {
    Solution solution;
    string testString = "(*))";
    if(solution.checkValidString(testString))
        cout << "The string is valid." << endl;
    else
        cout << "The string is not valid." << endl;
    return 0;
}
