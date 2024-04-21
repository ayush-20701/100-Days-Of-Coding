// Leetcode 1971 (Easy)
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> g;
        for(const auto& x : edges) {
            int u = x[0];
            int v = x[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        unordered_set<int> visited;
        return solve(g, visited, source, destination);
    }

    bool solve(unordered_map<int,vector<int>>& g, unordered_set<int>& visited, int curr, int dest) {
        if(curr == dest)
            return true;
        visited.insert(curr);
        for(int neighbour : g[curr]) {
            if(visited.find(neighbour) == visited.end()){
                if(solve(g, visited, neighbour, dest))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    int n = 5;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 3}, {3, 4}};
    int source = 0;
    int destination = 4;

    if(sol.validPath(n, edges, source, destination)) {
        cout << "There is a valid path from " << source << " to " << destination << endl;
    } else {
        cout << "There is no valid path from " << source << " to " << destination << endl;
    }

    return 0;
}