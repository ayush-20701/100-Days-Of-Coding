// Leetcode 1608 (easy) - Array
class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        size_t len = nums.size();
        for(int i = 1; i <= len; i++) {
            if(search(nums, i) == i)
                return i;
        }
        return -1;
    }
    int search(vector<int>& nums, int i) {
        int count = 0;
        for(int j = 0; j < nums.size(); j++){
            if(nums[j] >= i) count++;
        }
        return count;
    }
};