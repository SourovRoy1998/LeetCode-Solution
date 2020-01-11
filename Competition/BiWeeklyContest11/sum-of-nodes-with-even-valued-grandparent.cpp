//https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/

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
    int s=0;
    void helper(TreeNode* root){
        if(!root) return;
        if(root->val%2==0){
            if(root->left){
                if(root->left->left)
                    s+=root->left->left->val;
                if(root->left->right)
                    s+=root->left->right->val;
            }
            if(root->right){
                if(root->right->left)
                    s+=root->right->left->val;
                if(root->right->right)
                    s+=root->right->right->val;
            }
        }
        helper(root->left);
        helper(root->right);
    }
    
    
    int sumEvenGrandparent(TreeNode* root) {
        helper(root);
        return s;
    }
};
