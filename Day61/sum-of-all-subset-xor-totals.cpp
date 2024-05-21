// Leetcode 1863 (Easy)

class Solution {
private:
    int solve(vector<int> nums, int sum, int& ans, int index){
        //base case
        if(index >= nums.size()) {
            ans += sum;
            return ans;
        }

        //exclude
        ans = solve(nums, sum, ans, index+1);

        //include
        sum = nums[index] ^ sum;
        ans = solve(nums, sum, ans, index+1);

        return ans;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        return solve(nums, 0, ans, 0);
    }
};