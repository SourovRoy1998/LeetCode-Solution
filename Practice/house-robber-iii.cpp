//https://leetcode.com/problems/house-robber-iii/

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
    map<TreeNode*,int> hmap;
    int rob(TreeNode* root) {
        hmap[NULL] = 0;
        if(hmap.find(root)!=hmap.end())
            return hmap[root];
        int include=root->val;
        include+=root->left?rob(root->left->left)+rob(root->left->right):0;
        include+=root->right?rob(root->right->left)+rob(root->right->right):0;
        int exclude=rob(root->left)+rob(root->right);
        hmap[root]=max(include,exclude);
        return hmap[root];
    }
};
