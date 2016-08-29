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
    vector<int> res = {};
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return res;
        traver(root);
        return res;
    }
    void traver(TreeNode* root){
        if(root->left) traver(root->left);
        res.push_back(root->val);
        if(root->right) traver(root->right);
    }
};