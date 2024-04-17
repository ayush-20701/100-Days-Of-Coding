//Leetcode 988 (Medium)
#include <bits/stdc++.h>
using namespace std;

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
    void solve(TreeNode* node, std::string& least, std::string path) {
        // base case
        if(node == nullptr) return;

        // converting current node to char
        path += char('a' + node -> val); 

        if(node -> left == nullptr && node -> right == nullptr) {
            std::reverse(path.begin(), path.end());
            if(least.empty() || path < least) {
                least = path;
            }
            // backtrack
            std::reverse(path.begin(), path.end());
        }
        solve(node -> left, least, path);
        solve(node -> right, least, path);
    }
    std::string smallestFromLeaf(TreeNode* root) {
        std::string least;
        solve(root, least, "");
        return least;
    }
};

int main() {
    // Example usage
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(0);
    
    Solution solution;
    std::cout << "Smallest string from leaf node: " << solution.smallestFromLeaf(root) << std::endl;

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
