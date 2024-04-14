#include <iostream>

// Definition for a binary tree node.
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
    int solve(TreeNode* node, bool isLeft) { //recursive function
        //base case
        if (!node) {
            return 0;
        }
        if (!node->left && !node->right) {
            if(isLeft)
                return node->val;
            else
                return 0;
        }
        int left = solve(node->left, true); //traverse left
        int right = solve(node->right, false); //traverse right
        return left + right;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root, false);
    }
};

int main() {
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Creating an instance of the Solution class
    Solution solution;

    // Calling the sumOfLeftLeaves function
    int sum = solution.sumOfLeftLeaves(root);

    // Outputting the result
    std::cout << "Sum of left leaves: " << sum << std::endl;

    // Freeing the allocated memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
