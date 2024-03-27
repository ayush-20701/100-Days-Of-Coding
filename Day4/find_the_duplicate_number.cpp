//Leetcode 287

//Floyd's Hare and Tortoise algorithm
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];
        
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        fast = 0;

        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        } 
        return slow;
    }
};

int main() {
    // Example input
    vector<int> nums = {1, 3, 4, 2, 2}; // Contains a duplicate: 2

    Solution solution;
    int duplicate = solution.findDuplicate(nums);

    cout << "Duplicate number: " << duplicate << endl;

    return 0;
}
