// Last updated: 30/07/2026, 10:24:20
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
    int minDepth(TreeNode* root) {
        // Base case: empty tree has a depth of 0
        if (root == nullptr) {
            return 0;
        }
        
        // If the left subtree is empty, we must find the min depth of the right subtree
        if (root->left == nullptr) {
            return minDepth(root->right) + 1;
        }
        
        // If the right subtree is empty, we must find the min depth of the left subtree
        if (root->right == nullptr) {
            return minDepth(root->left) + 1;
        }
        
        // If both subtrees exist, take the minimum of both depths plus 1 for the current node
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};