// Last updated: 30/07/2026, 10:22:40
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) {
            return result;
        }
        
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;
        
        q.push({root, {0, 0}});
        
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            
            TreeNode* node = p.first;
            int col = p.second.first;
            int row = p.second.second;
            
            nodes[col][row].insert(node->val);
            
            if (node->left) {
                q.push({node->left, {col - 1, row + 1}});
            }
            if (node->right) {
                q.push({node->right, {col + 1, row + 1}});
            }
        }
        
        for (auto p_col : nodes) {
            vector<int> col_nodes;
            for (auto p_row : p_col.second) {
                col_nodes.insert(col_nodes.end(), p_row.second.begin(), p_row.second.end());
            }
            result.push_back(col_nodes);
        }
        
        return result;
    }
};