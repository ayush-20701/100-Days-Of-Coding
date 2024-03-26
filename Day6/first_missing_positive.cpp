class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int index = 1;
        for(int i = 0; i < nums.size(); i++) {
            //skipping non-positive numbers
            if(nums[i] <= 0) 
                continue;

            // If current number matches index, increment index
            if(nums[i] == index)
                index++;

            // If current number is greater than index, it's the missing positive number
            else if(nums[i] > index)
                return index;
        }
        
        // If all positive numbers are consecutive, return the next index
        return index;
    }
};