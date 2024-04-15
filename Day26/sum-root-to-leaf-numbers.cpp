// Leetcode 129 (Medium)
#include <bits/stdc++.h>
using namespace std;

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
    int solve(TreeNode* root, int sum) {
        if(!root)
            return 0;
        sum = sum*10 + root->val;
        if(!root -> left && !root -> right)
            return sum;
        return solve(root -> left, sum) + solve(root -> right, sum);
    }

    int sumNumbers(TreeNode* root) {
        return solve(root, 0);
    }
};

// Function to create a binary tree from an array
TreeNode* createBinaryTree(int arr[], int n, int i) {
    TreeNode* root = nullptr;
    if (i < n) {
        root = new TreeNode(arr[i]);
        root->left = createBinaryTree(arr, n, 2 * i + 1);
        root->right = createBinaryTree(arr, n, 2 * i + 2);
    }
    return root;
}

// Function to deallocate memory used for the binary tree
void deleteBinaryTree(TreeNode* root) {
    if (root) {
        deleteBinaryTree(root->left);
        deleteBinaryTree(root->right);
        delete root;
    }
}

int main() {
    // Example usage
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    Solution sol;
    TreeNode* root = createBinaryTree(arr, n, 0);
    std::cout << "Sum of numbers formed by paths in the binary tree: " << sol.sumNumbers(root) << std::endl;
    deleteBinaryTree(root); // Deallocate memory
    return 0;
}
