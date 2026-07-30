// Last updated: 30/07/2026, 10:24:24
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        bool left_to_right = true;
        
        while (!q.empty()) {
            int size = q.size();
            vector<int> current_level(size);
            
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                int index = left_to_right ? i : (size - 1 - i);
                current_level[index] = node->val;
                
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            
            result.push_back(current_level);
            left_to_right = !left_to_right;
        }
        
        return result;
    }
};