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
    vector<int> preorderTraversal(TreeNode* root) {
        if (root==NULL) {
            return vector<int>();
        }
        vector<int> result;
        stack<TreeNode *> treeStack;
        treeStack.push(root);
        while(!treeStack.empty()){
            auto temp = treeStack.top();
            result.push_back(temp->val);
            treeStack.pop();
            if(temp->right)
                treeStack.push(temp->right);
            if(temp->left)
                treeStack.push(temp->left);
        }
        return result;
    }
};