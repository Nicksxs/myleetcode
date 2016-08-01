/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int dir = 0, layer = 1;
        vector<vector<int>> result;
        helper(result, root, dir, layer);
        return result;
    }
    void helper(vector<vector<int>> &result, TreeNode *root, int dir, int layer) {
        if (!root) return;
        if (result.size() < layer) result.push_back(vector<int>(1, root->val));
        else {
            if (dir == 1) result[layer-1].push_back(root->val);
            else result[layer-1].insert(result[layer-1].begin(), root->val);
        }
        dir += 1;
        TreeNode *first = (dir == 0) ? root->left : root->right;
        TreeNode *second = (dir == 0) ? root->right : root->left; 
        helper(result, first, dir % 2, layer + 1);
        helper(result, second, dir % 2, layer + 1);
    }
};