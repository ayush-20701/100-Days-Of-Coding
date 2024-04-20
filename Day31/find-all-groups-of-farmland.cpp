// Leetcode 1992
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;

        for(int i = 0; i < land.size(); i++) {
            for(int j = 0; j < land[0].size(); j++) {
                if(land[i][j] == 1)
                    ans.push_back(solve(land, i, j));
            }
        }
        return ans;
    }
private:
    vector<int> solve(vector<vector<int>>& land, int row, int col) {
        vector<int> coordinates = {row, col};
        int x = row;
        int y = col;

        while(x < land.size() && land[x][col] == 1) 
            x++;
        while(y < land[0].size() && land[row][y] == 1)
            y++;
        
        coordinates.push_back(x-1);
        coordinates.push_back(y-1);

        for(int i = row; i <= x-1; i++) {
            for(int j = col; j <= y-1; j++) 
                land[i][j] = 0;
        }
        return coordinates;
    }
};

int main() {
    Solution solution;

    // Example usage
    vector<vector<int>> land = {
        {1, 0, 0},
        {0, 1, 1},
        {0, 1, 1}
    };

    vector<vector<int>> farmlands = solution.findFarmland(land);

    cout << "Farmland coordinates:\n";
    for (const auto& farmland : farmlands) {
        for (int coord : farmland) {
            cout << coord << " ";
        }
        cout << endl;
    }

    return 0;
}