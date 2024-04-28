// Leetcode 834 (hard)
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {

        vector<vector<int>> graph(n);
        vector<int> subtree_count(n);
        vector<int> total_distance(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        dfs(0, -1, graph, subtree_count, total_distance);
        dfs2(0, -1, n, graph, subtree_count, total_distance);

        return total_distance;
    }

    void dfs(int node, int parent, vector<vector<int>>& graph, vector<int>& subtree_count, vector<int>& total_distance) {
        subtree_count[node] = 1;
        for (int child : graph[node]) {
            if (child != parent) {
                dfs(child, node, graph, subtree_count, total_distance);
                subtree_count[node] += subtree_count[child];
                total_distance[node] +=
                    total_distance[child] + subtree_count[child];
            }
        }
    }

    void dfs2(int node, int parent, int n, vector<vector<int>>& graph, vector<int>& subtree_count, vector<int>& total_distance) {
        for (int child : graph[node]) {
            if (child != parent) {
                total_distance[child] = total_distance[node] -
                                        subtree_count[child] +
                                        (n - subtree_count[child]);
                dfs2(child, node, n, graph, subtree_count, total_distance);
            }
        }
    }
};

int main() {
    Solution sol;
    int n = 6;
    vector<vector<int>> edges = {{0,1},{0,2},{2,3},{2,4},{2,5}};
    vector<int> result = sol.sumOfDistancesInTree(n, edges);
    
    for (int i = 0; i < n; ++i) {
        cout << result[i] << ", ";
    }

    return 0;
}