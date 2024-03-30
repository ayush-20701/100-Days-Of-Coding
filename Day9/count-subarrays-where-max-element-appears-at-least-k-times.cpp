//Leetcode 2962
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long int ans = 0, count = 0, i = 0, j = 0;
        long long int max = *max_element(nums.begin(), nums.end());
        long long int n = nums.size();

        while (j < n) {
            if (nums[j] == max) count++;
            while (count >= k) {
                if (nums[i] == max) count--;
                i++;
                ans += n - j;
            }
            j++;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 3, 2, 2, 3};
    int k = 2;
    long long int result = sol.countSubarrays(nums, k);
    cout << "Number of subarrays with at least " << k << " elements: " << result << endl;
    return 0;
}
