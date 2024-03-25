/* Approach
Initialize an empty vector ans to store the duplicates.
Iterate through the array nums.
For each element nums[i], take its absolute value x.
Check if nums[x-1] is negative.
If it is, then x is a duplicate, so add it to ans.
Otherwise, mark nums[x-1] as negative.
Return ans. */

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        int n=size(nums);
        for(int i=0;i<n;i++){
            int x=abs(nums[i]);
            if(nums[x-1]<0){
                
                ans.push_back(x);
            }
            nums[x-1]*=-1;
        }
        return ans;
    }
};