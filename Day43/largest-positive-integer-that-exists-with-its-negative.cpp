// Leetcode 2441 (Easy)
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        while(i < nums.size()){
            if(nums[i] < 0) {
                int neg = abs(nums[i]);
                if(find(neg, nums)) return neg;
            }
            i++;
        }
        return -1;
    }
    bool find(int neg, vector<int>& nums){
        int i = 0;
        while(i < nums.size()) {
            if(nums[i] > 0) {
                if(nums[i] == neg) return true;
            }
            i++;
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {-1, 10, 6, 7, -7, 1};

    int maxK = solution.findMaxK(nums);

    if (maxK != -1) {
        cout << "Maximum K found: " << maxK << endl;
    } else {
        cout << "No such K exists." << endl;
    }

    return 0;
}