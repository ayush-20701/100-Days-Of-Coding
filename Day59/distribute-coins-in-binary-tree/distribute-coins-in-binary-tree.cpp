// Leetcode 979 (Medium)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
    int solve(TreeNode* root, int &ans){
        //base case
        if(root == NULL) return 0;
        int leftNode = solve(root -> left, ans);
        int rightNode = solve(root -> right, ans);
        ans += abs(leftNode) + abs(rightNode);
        return (root -> val - 1) + leftNode + rightNode;
    }
};