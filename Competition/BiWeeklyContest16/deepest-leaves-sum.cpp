//https://leetcode.com/contest/biweekly-contest-16/problems/deepest-leaves-sum/

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
    int ans=0;
    int height(TreeNode* root){
        if(!root) return 0;
        return max(height(root->left),height(root->right))+1;
    }
    
    void S(TreeNode* root, int h, int x){
        if(!root) return;
        if(x==h) ans+=root->val;
        S(root->left,h,x+1);
        S(root->right,h,x+1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int h=height(root)-1;
        S(root,h,0);
        return ans;
            
    }
};
