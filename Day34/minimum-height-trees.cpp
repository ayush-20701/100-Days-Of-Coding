// Leetcode 310
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n); //to store adjacency list
        vector<int> inDegree(n, 0), ans;
        for(auto &e : edges) { //creating adjacency list for tree
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            inDegree[e[0]]++;
            inDegree[e[1]]++;
        }

        queue<int> q; //to store nodes with degree 1
        for(int i = 0; i < n; i++) {
            if(inDegree[i] == 1) q.push(i), inDegree[i]--;
        }

        while(!q.empty()) { //BFS traversal
            int s = q.size();
            ans.clear();    //clearing answer array for each iteration
            for(int i = 0; i < s; i++) {
                int curr = q.front();
                q.pop();
                ans.push_back(curr);
                for(auto child : graph[curr]) {
                    inDegree[child]--;
                    if(inDegree[child] == 1) q.push(child);
                }
            } 
        }
        //edge case
        if(n == 1) ans.push_back(0);

        return ans;
    }
};

int main() {
    Solution solution;
    int n = 6;
    vector<vector<int>> edges = {{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}};
    vector<int> minHeightTrees = solution.findMinHeightTrees(n, edges);
    
    cout << "Minimum Height Trees: ";
    for (int node : minHeightTrees) {
        cout << node << " ";
    }
    cout << endl;
    
    return 0;
}