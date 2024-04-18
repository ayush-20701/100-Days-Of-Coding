// Leetcode 463 (easy)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int islandPerimeter(std::vector<std::vector<int>>& grid) {
        int ans = 0;
       
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    ans += 4;
                    if(i > 0 && grid[i-1][j] == 1)
                        ans -= 2;
                    if(j > 0 && grid[i][j-1] == 1)
                        ans -=2;
                }
            }
        }
        return ans;
    } 
};

int main() {
    std::vector<std::vector<int>> grid = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    Solution sol;
    int perimeter = sol.islandPerimeter(grid);
    std::cout << "Perimeter of the island: " << perimeter << std::endl;
    return 0;
}
