//Leetcode 46

#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void solve(vector<int> nums, int index, vector<vector<int>> &ans)
    {
        // base case
        if (index >= nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for (int j = index; j < nums.size(); j++)
        {
            swap(nums[index], nums[j]);
            solve(nums, index + 1, ans);
            swap(nums[index], nums[j]); // backtrack
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int index = 0;
        solve(nums, index, ans);
        return ans;
    }
};
int main()
{
    // Example input
    vector<int> nums = {1, 2, 3};

    Solution solution;
    vector<vector<int>> permutations = solution.permute(nums);

    // Output the permutations
    cout << "Permutations of [1, 2, 3] are:\n";
    for (const auto &permutation : permutations)
    {
        cout << "[ ";
        for (const auto &num : permutation)
        {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}