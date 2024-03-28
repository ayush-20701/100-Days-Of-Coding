//Leetcode 2958
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> map;
        int n = nums.size();

        for (int l = 0, r = 0; r < n; r++) {
            map[nums[r]]++;  //inserting value in windows from right

            //if frequency of newly inserted element exceeds k then pop it from left
            if (map[nums[r]] > k) {
                while (nums[l] != nums[r]) {
                    map[nums[l]]--;
                    l++;
                }
                map[nums[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;
    int maxLength = sol.maxSubarrayLength(nums, k);
    cout << "Maximum subarray length with at most " << k << " distinct elements: " << maxLength << endl;
    return 0;
}
