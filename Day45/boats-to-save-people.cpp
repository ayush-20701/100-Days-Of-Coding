// Leetcode 881 (Medium)
#include <bits/stdc++.h>

class Solution {
public:
    int numRescueBoats(std::vector<int>& people, int limit) {
        int boats = 0;
        sort(people.begin(), people.end());
        int i = 0, j = people.size()-1;
        while(i <= j) {
            if ((people[j] + people[i]) <= limit) {
                i++;
            }
            j--;
            boats++;
        }
        return boats;
    }
};

int main() {
    Solution solution;
    std::vector<int> people = {3, 1, 7, 4, 2, 6, 5};
    int limit = 7;
    std::cout << "Number of rescue boats needed: " << solution.numRescueBoats(people, limit) << std::endl;
    return 0;
}
