// Last updated: 30/07/2026, 10:24:06
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();

            // Insert at the front to naturally reverse the Root -> Right -> Left order 
            // into Left -> Right -> Root
            result.insert(result.begin(), curr->val);

            // Push left first, then right, so that right is popped first
            if (curr->left != nullptr) {
                st.push(curr->left);
            }
            if (curr->right != nullptr) {
                st.push(curr->right);
            }
        }

        return result;
    }
};