//Leetcode 17
#include <bits/stdc++.h>
using namespace std;
class Solution {
    void solve(string digits, string output, int index, vector<string>& ans, string mapping[])
    {
        //base case
        if(index >= digits.length()) {
            ans.push_back(output);
            return;
        }
        int number = digits[index] - '0';
        string value = mapping[number];
        for(int i = 0; i < value.length(); i++)
        {
            output.push_back(value[i]);
            solve(digits, output, index+1, ans, mapping);
            output.pop_back(); //backtrack
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0)
            return ans;
        string output = "";
        int index = 0;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, output, index, ans, mapping);
        return ans;
    }
};
int main() {
    Solution solution;
    string digits = "23"; // Example input
    vector<string> combinations = solution.letterCombinations(digits);
    
    // Output the combinations
    cout << "Letter Combinations for " << digits << " are:\n";
    for (const string& combination : combinations) {
        cout << combination << "\n";
    }

    return 0;
}