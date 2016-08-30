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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> retVal;
        orderTraver(root, retVal, 0);
        reverse(retVal.begin(), retVal.end());
        return retVal;
    }
    void orderTraver(TreeNode* root, vector<vector<int>> &v, int currLevel){
        if(root == NULL) return;
        
        if(v.empty() || currLevel > (v.size() -1))
            v.push_back(vector<int>());
        v[currLevel].push_back(root->val);
        if(root->left) orderTraver(root->left, v, currLevel + 1);
        if(root->right) orderTraver(root->right, v, currLevel + 1);
    }
    
    
    
    
    
    
//     vector<vector<int> > levelOrderBottom(TreeNode *root) {
// 	vector<vector<int> > retVal;

// 	levelOrder(root, retVal, 0);

// 	reverse(retVal.begin(), retVal.end());

// 	return retVal;
// }

// void levelOrder(TreeNode* root, vector<vector<int> > &v, int currLevel) {
// 	if (root == NULL) {
// 		return;
// 	}

// 	if (v.empty() || currLevel > (v.size() - 1)) {
// 		v.push_back(vector<int>());
// 	}

// 	v[currLevel].push_back(root->val);

// 	levelOrder(root->left, v, currLevel + 1);
// 	levelOrder(root->right, v, currLevel + 1);
// }
};