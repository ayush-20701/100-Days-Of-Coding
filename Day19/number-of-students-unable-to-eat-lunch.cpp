// Leetcode 1700 (easy)
// Disclaimer: This is a very brute force solution which I came up with.
// This has a terrible TC of O(m*n), where m and n is no. of sandwiches and students respectively.
// I'll upload screenshots of better optimized solution in this folder :-) 
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> studs;
        // inserting students into a queue
        for (int i = 0; i < students.size(); ++i)
            studs.push(students[i]);

        for (int i = 0; i < sandwiches.size(); i++) {
            if (studs.front() == sandwiches[i]) {
                studs.pop();
                continue;
            }
            int j = (sandwiches.size() - i);

            while (j != 0) {
                studs.push(studs.front());
                studs.pop();
                if (studs.front() == sandwiches[i]) {
                    studs.pop();
                    break;
                }
                j--;
            }
            if(j == 0) break;
        }
        return studs.size();
    }
};

int main() {
    Solution solution;
    vector<int> students = {1, 1, 0, 0};
    vector<int> sandwiches = {0, 1, 1, 0};
    cout << "Remaining students: " << solution.countStudents(students, sandwiches) << endl;
    return 0;
}
