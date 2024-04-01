// Leetcode 58
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        bool count = false;
        for(int i = s.length() - 1; i >= 0; i--) {
            if(s[i] != ' ') {
                count = true;
                length++;
            }
            else if(count) {
                break;
            }
        }
        return length;
    }
};

int main() {
    Solution sol;

    // Test cases
    string s1 = "Hello World";
    string s2 = "   Hello  ";
    string s3 = "a ";
    
    cout << "Length of last word in \"" << s1 << "\": " << sol.lengthOfLastWord(s1) << endl;
    cout << "Length of last word in \"" << s2 << "\": " << sol.lengthOfLastWord(s2) << endl;
    cout << "Length of last word in \"" << s3 << "\": " << sol.lengthOfLastWord(s3) << endl;

    return 0;
}
