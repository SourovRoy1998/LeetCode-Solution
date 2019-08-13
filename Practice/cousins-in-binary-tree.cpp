//https://leetcode.com/problems/cousins-in-binary-tree/

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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*, int>> Q;
        Q.push({root,0});
        int h1=-1,h2=-2;
        
        while(!Q.empty()){
            int n=Q.size();
            for(int i=0;i<n;i++){
                pair<TreeNode*,int> temp=Q.front();Q.pop();
                if(temp.first->val==x) h1=temp.second;
                if(temp.first->val==y) h2=temp.second;
                if(temp.first->left && temp.first->left->val==x && temp.first->right && temp.first->right->val==y) return false;
                if(temp.first->left && temp.first->left->val==y && temp.first->right && temp.first->right->val==x) return false;
                if(temp.first->left)Q.push({temp.first->left,temp.second+1});
                if(temp.first->right)Q.push({temp.first->right,temp.second+1});
            }
            if(h1==h2) return true;
        }
        return false;
    }
};
