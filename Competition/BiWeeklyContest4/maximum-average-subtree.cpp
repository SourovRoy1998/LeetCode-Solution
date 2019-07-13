//https://leetcode.com/contest/biweekly-contest-4/problems/maximum-average-subtree/

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
    vector<int> helper(TreeNode* root, double& max_avg){
        if(root==NULL) return {0,0};
        vector<int> L=helper(root->left,max_avg);
        vector<int> R=helper(root->right,max_avg);
        double avg=(double)(L[0]+R[0]+root->val)/(L[1]+R[1]+1);
        max_avg=max(max_avg,avg);
        return {L[0]+R[0]+root->val,L[1]+R[1]+1};
    }
    
    
    double maximumAverageSubtree(TreeNode* root) {
        double max_avg=0.0;
        helper(root,max_avg);
        return max_avg;
    }
};
