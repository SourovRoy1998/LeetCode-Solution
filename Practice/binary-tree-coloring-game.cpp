//https://leetcode.com/problems/binary-tree-coloring-game/

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
    int left,right;
    int count(TreeNode* root, int x){
        if(!root) return 0;
        int l=count(root->left,x);
        int r=count(root->right,x);
        if(root->val==x) {left=l;right=r;}
        return l+r+1;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        count(root,x);
        return max(max(left,right),n-left-right-1)>n/2;
    }
};
