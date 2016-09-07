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
    int minDepth(TreeNode* root) {
        // if(!root) return 0;
        // if(!root->left) return 1 + minDepth(root->right);
        // if(!root->right) return 1 + minDepth(root->left);
        // return 1 + min(minDepth(root->left),minDepth(root->right));
        // Start typing your C/C++ solution below  
      // DO NOT write int main() function  
      if(root == NULL)  
        return 0;  
      int lmin = minDepth(root->left);  
      int rmin = minDepth(root->right);  
      if(lmin ==0 && rmin ==0)  
        return 1;  
      if(lmin ==0)  
      {  
        lmin = INT_MAX;  
      }  
      if(rmin ==0)  
      {  
        rmin = INT_MAX;  
      }  
      return min(lmin, rmin) +1;  
    }
};