//https://leetcode.com/contest/weekly-contest-110/problems/range-sum-of-bst/


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
    void Sum(TreeNode* root, int L, int R, int& sum){
        if(root==NULL) return;
        Sum(root->left,L,R,sum);
        if(root->val>=L && root->val<=R) sum+=root->val;
        Sum(root->right,L,R,sum);
        
    }
    
    
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum=0;
        bool start=false;
        Sum(root,L,R,sum);
        return sum;
    }
};
