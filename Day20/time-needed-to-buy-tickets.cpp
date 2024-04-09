// Leetcode 2073
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;

        for(int i = 0; i < tickets.size(); i++) {
            if(i <= k)
                time += min(tickets[i], tickets[k]);
            else
                time += min(tickets[i], tickets[k] - 1);
        }
        return time;
    }
};

int main() {
    Solution solution;
    vector<int> tickets = {2, 3, 4, 5, 6}; // Example ticket prices
    int k = 2; // Index of the ticket you are buying
    cout << "Time required to buy: " << solution.timeRequiredToBuy(tickets, k) << endl;
    return 0;
}
