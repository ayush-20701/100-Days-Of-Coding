#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {        
        if(grid.empty() || grid[0].empty())
            return 0;
        
        int ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    ans++;
                    solve(grid, i, j);
                }
            }
        }
        return ans;
    }
    void solve(vector<vector<char>>& grid, int i, int j){
        //base case
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0') 
            return;

        grid[i][j] = '0';

        solve(grid, i - 1, j); //for up
        solve(grid, i + 1, j); //for down
        solve(grid, i , j + 1); //for right
        solve(grid, i , j - 1); //for left
    }
};
int main() {
    std::vector<std::vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    Solution sol;
    int numIslands = sol.numIslands(grid);
    std::cout << "Number of islands: " << numIslands << std::endl;
    return 0;
}