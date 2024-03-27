//Leetcode 713
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0, right = 0, product = 1, count = 0;
        int n = nums.size();
        if (k <= 1) return 0;
        while (right < n) {
            product *= nums[right];
            while (product >= k) product /= nums[left++];
            count += 1 + (right - left);
            right++;
        }
        return count;
    }
};

int main() {
    // Example input
    vector<int> nums = {10, 5, 2, 6};
    int k = 100; // Expected output: 8

    Solution solution;
    int count = solution.numSubarrayProductLessThanK(nums, k);

    cout << "Number of subarrays with product less than " << k << ": " << count << endl;

    return 0;
}