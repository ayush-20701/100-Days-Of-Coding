// Leetcode 131 (medium)
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> output;
        solve(ans, output, s, 0);      
        return ans;
    }
    void solve(vector<vector<string>>& ans, vector<string>& output, string& s, int i) {
        //base case
        if(i == s.length()) {
            ans.push_back(output);
            return;
        }

        for(int j = i + 1; j <= s.length(); j++) {
            if(palindrome(s, i, j-1)) {
                output.push_back(s.substr(i, j-i));
                //recursive call
                solve(ans, output, s, j);
                //backtrack
                output.pop_back();
            }
        }
    }

    bool palindrome(string &str, int i, int j) {
        while(i < j) {
            if(str[i] != str[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};