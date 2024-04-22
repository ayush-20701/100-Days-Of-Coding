// Leetcode 752 (medium)
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadendSet(deadends.begin(), deadends.end());
        if (deadendSet.count("0000")) {
            return -1;
        }
        
        queue<pair<string, int>> queue;
        queue.push({"0000", 0});
        unordered_set<string> visited;
        visited.insert("0000");
        
        while (!queue.empty()) {
            auto current = queue.front();
            queue.pop();
            string currentCombination = current.first;
            int moves = current.second;
            
            if (currentCombination == target) {
                return moves;
            }
            
            for (int i = 0; i < 4; i++) {
                for (int delta : {-1, 1}) {
                    int newDigit = (currentCombination[i] - '0' + delta + 10) % 10;
                    string newCombination = currentCombination;
                    newCombination[i] = '0' + newDigit;
                    
                    if (visited.find(newCombination) == visited.end() && deadendSet.find(newCombination) == deadendSet.end()) {
                        visited.insert(newCombination);
                        queue.push({newCombination, moves + 1});
                    }
                }
            }
        }
        
        return -1; // Target is not reachable
    }
};

int main() {
    vector<string> deadends = {"0201", "0101", "0102", "1212", "2002"};
    string target = "0202";
    Solution sol;
    int moves = sol.openLock(deadends, target);
    if (moves != -1) {
        cout << "Minimum number of turns to reach " << target << " from 0000 is: " << moves << endl;
    } else {
        cout << "Target " << target << " is not reachable from 0000." << endl;
    }
    return 0;
}
