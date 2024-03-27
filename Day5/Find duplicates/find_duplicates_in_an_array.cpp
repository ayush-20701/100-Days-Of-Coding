/* Approach
Initialize an empty vector ans to store the duplicates.
Iterate through the array nums.
For each element nums[i], take its absolute value x.
Check if nums[x-1] is negative.
If it is, then x is a duplicate, so add it to ans.
Otherwise, mark nums[x-1] as negative.
Return ans. */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int x = abs(nums[i]);
            if (nums[x - 1] < 0) {
                ans.push_back(x);
            }
            nums[x - 1] *= -1;
        }
        return ans;
    }
};

int main() {
    // Example input
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1}; // Contains duplicates: 2, 3

    Solution solution;
    vector<int> duplicates = solution.findDuplicates(nums);

    cout << "Duplicates: ";
    for (int num : duplicates) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}