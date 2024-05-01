#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        vector<char> charVector(word.begin(), word.end());
        for(int i = 0; i < charVector.size(); i++) {
            if(charVector[i] == ch) {
                int j = i;
                reverse(charVector, j);
                break;
            }
        }
        string result(charVector.begin(), charVector.end());
        return result;
    }
    void reverse(vector<char> &charVector, int j){
        int i = 0;
        while(i < j) {
            char temp = charVector[j];
            charVector[j] = charVector[i];
            charVector[i] = temp;
            i++;
            j--;
        }
    }
};

int main() {
    Solution solution;
    string word = "abcdefg";
    char ch = 'd';
    cout << "Original word: " << word << endl;
    string reversedPrefix = solution.reversePrefix(word, ch);
    cout << "Word after reversing prefix up to '" << ch << "': " << reversedPrefix << endl;
    return 0;
}
