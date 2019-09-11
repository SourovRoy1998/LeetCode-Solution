//https://leetcode.com/problems/binary-tree-paths/

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
    void helper(TreeNode* root, vector<string>& result,string curr){
        if(root->left==NULL && root->right==NULL) result.push_back(curr);
        if(root->left) helper(root->left,result,curr+"->"+to_string(root->left->val));
        if(root->right) helper(root->right,result,curr+"->"+to_string(root->right->val));
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if(root==NULL) return {};
        helper(root,result,to_string(root->val));
        return result;
    }
};
