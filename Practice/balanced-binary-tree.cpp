//https://leetcode.com/problems/balanced-binary-tree/

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
    int helper(TreeNode* root, bool& flag){
        if(!root) return 0;
        int h1=helper(root->left,flag);
        int h2=helper(root->right,flag);
        if(abs(h1-h2)>1) flag=false;
        return max(h1,h2)+1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        bool flag=true;
        helper(root, flag);
        return flag;
    }
};
