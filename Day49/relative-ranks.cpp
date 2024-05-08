// Leetcode 506 (Easy)
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> answer(n);
        vector<int> sorted_score = score;
        sort(sorted_score.begin(), sorted_score.end(), greater<int>());
        int i = 0;
        for (int i = 0; i < n; ++i) {
            int target = sorted_score[i];
            auto it = find(score.begin(), score.end(), target);
            int index = distance(score.begin(), it);
            if (i == 0)
                answer[index] = "Gold Medal";
            else if (i == 1)
                answer[index] = "Silver Medal";
            else if (i == 2)
                answer[index] = "Bronze Medal";
            else
                answer[index] = to_string(i+1); // Convert rank to string
        }
        return answer;
    }
};