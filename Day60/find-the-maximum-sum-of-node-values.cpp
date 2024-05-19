//Leetcode 3068 (Hard)

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum = 0, cnt = 0, bkb = LLONG_MAX; //bkb : bali ka bakra
        for(auto el : nums) {
            if((el^k) > el) {
                sum += el^k;
                bkb = min(bkb, (long long)(el^k) - el);
                cnt++; 
            }
            else{
                sum += el;
                bkb = min(bkb, (long long)el - (el^k));
            }
        }
        if(cnt % 2 == 0) return sum;
        return sum - bkb;
    }
};