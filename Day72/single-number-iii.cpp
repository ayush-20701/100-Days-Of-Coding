// Leetcode 260 (Medium)
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int n : nums) {
            map[n]++;
        }

        vector<int> ans;
        for (auto& pair : map) {
            if (pair.second == 1) {
                ans.push_back(pair.first);
            }
        }

        return ans;
    }
};