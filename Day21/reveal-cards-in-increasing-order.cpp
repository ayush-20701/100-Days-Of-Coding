// Leetcode 950
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());

        int n = deck.size();
        vector<int> result(n);
        deque<int> indices;

        for(int i = 0; i < n; i++){
            indices.push_back(i);
        }

        for(int card : deck) {
            int index = indices.front();
            indices.pop_front();
            result[index] = card;
            if(!indices.empty()) {
                indices.push_back(indices.front());
                indices.pop_front();
            }
        }
        return result;
    }
};

int main() {
    vector<int> deck = {1, 2, 3, 4, 5, 6, 7};
    Solution sol;
    vector<int> result = sol.deckRevealedIncreasing(deck);

    cout << "Resultant deck: ";
    for(int card : result) {
        cout << card << " ";
    }
    cout << endl;

    return 0;
}