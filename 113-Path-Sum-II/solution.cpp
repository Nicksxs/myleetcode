/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        vector<vector<int> > allPaths;
        finaPathSum(root, sum, path, allPaths);
        return allPaths;
    }
    void finaPathSum(TreeNode *root, int sum, vector<int> &path, vector<vector<int> > &allPaths) {
        if(!root) return;
        sum -= root->val;
        path.push_back(root->val);
        
        if(!root->left && !root->right) {
            if(sum==0) {
                allPaths.push_back(path);
            }
        }
        else {
            if(root->left) finaPathSum(root->left, sum, path, allPaths);
            if(root->right) finaPathSum(root->right, sum, path, allPaths);
        }
        
        path.pop_back();
    }
};