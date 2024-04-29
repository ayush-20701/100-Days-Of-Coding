// Leetcode 2997 (Medium)
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        for(int n : nums) {
            ans = ans ^ n;
        }
        int count = 0;
        while(k || ans) {
            if((k % 2) != (ans % 2))
                count++;
            k /= 2;
            ans /= 2;
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 1, 3, 4};
    int k = 1;
    cout << "Minimum operations required: " << sol.minOperations(nums, k) << endl;
    return 0;
}