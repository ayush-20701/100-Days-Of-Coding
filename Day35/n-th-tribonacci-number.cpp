// Leetcode 1137
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        else if(n == 1 || n == 2) return 1;
        
        vector<int> list(n + 1);
        list[1] = 1;
        list[2] = 1;
        
        for (int i = 3; i <= n; i++) {
            list[i] = list[i - 1] + list[i - 2] + list[i - 3];
        }
        
        return list[n];
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "The " << n << "th tribonacci number is: " << solution.tribonacci(n) << endl;
    return 0;
}
