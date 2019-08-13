//https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> result;
        queue<TreeNode*> Q;
        Q.push(root);
        vector<int> temp;
        
        while(!Q.empty()){
            int n=Q.size();
            temp={};
            for(int i=0;i<n;i++){
                TreeNode* node=Q.front();
                Q.pop();
                temp.push_back(node->val);
                if(node->left) Q.push(node->left);
                if(node->right) Q.push(node->right);
            }
            result.push_back(temp);
            
        }
        return result;
    }
};
