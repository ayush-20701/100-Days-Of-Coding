// Leetcode 2444
#include <bits/stdc++.h>c:\Users\ayush\Pictures\Screenshots\Screenshot 2024-04-01 001837.png

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int temp = -1, left = -1, right = -1;

        for (int i = 0; i < nums.size(); ++i) {
            if (!(minK <= nums[i] && nums[i] <= maxK)) {
                temp = i;
            }

            if (nums[i] == minK) {
                left = i;
            }

            if (nums[i] == maxK) {
                right = i;
            }

            ans += max(0, min(left, right) - temp);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 2, 5, 4, 6};
    int minK = 2;
    int maxK = 4;
    
    cout << "Number of subarrays with minK = " << minK << " and maxK = " << maxK << " is: " 
         << sol.countSubarrays(nums, minK, maxK) << endl;
    
    return 0;
}