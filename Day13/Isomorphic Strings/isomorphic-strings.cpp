// Leetcode 205

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> iS(200, 0); 
        vector<int> iT(200, 0); 
        
        if(s.length() != t.length()) 
            return false;
        
        for(int i = 0; i < s.length(); i++) { 

            if(iS[s[i]] != iT[t[i]]) { 
                return false; 
            }
            
            iS[s[i]] = i + 1; 
            iT[t[i]] = i + 1;
        }
        
        return true; 
    }
};

int main() {
    Solution solution;

    // Test cases
    string s1 = "egg", t1 = "add";
    string s2 = "foo", t2 = "bar";
    string s3 = "paper", t3 = "title";

    cout << "Isomorphic for s1 and t1: " << solution.isIsomorphic(s1, t1) << endl;
    cout << "Isomorphic for s2 and t2: " << solution.isIsomorphic(s2, t2) << endl;
    cout << "Isomorphic for s3 and t3: " << solution.isIsomorphic(s3, t3) << endl;

    return 0;
}
