// Leetcode 3075 (Medium)
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        long int ans = 0;
        int x = 0;
        for(long long int i = 0; i < happiness.size(); i++) {
            happiness[i] -= x;
            if(happiness[i] > 0)
                ans += happiness[i];
            else
                ans += 0;
            x++;
            k--;
            if(k == 0) break;
        }
        return ans;
    }
};