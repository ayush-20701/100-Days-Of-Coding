// Leetcode 623
#include <iostream>

// Definition for a binary tree node
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* solve(TreeNode* root, int val, int depth, int curr) {
        if (!root)
            return nullptr;

        if (curr == depth - 1) {
            TreeNode* leftNode = root->left;
            TreeNode* rightNode = root->right;

            root->left = new TreeNode(val);
            root->right = new TreeNode(val);

            root->left->left = leftNode;
            root->right->right = rightNode;

            return root;
        }
        root->left = solve(root->left, val, depth, curr + 1);
        root->right = solve(root->right, val, depth, curr + 1);
        return root;
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        return solve(root, val, depth, 1);
    }
};

int main() {
    Solution solution;
    
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(5);

    // Adding a row with value 1 at depth 2
    int val = 1;
    int depth = 2;
    TreeNode* modifiedRoot = solution.addOneRow(root, val, depth);

    // Displaying the modified tree
    std::cout << "Modified tree after adding a row with value " << val << " at depth " << depth << ":\n";
    // You can implement a tree traversal method (e.g., inorder, preorder, postorder) to display the tree.
    
    return 0;
}
