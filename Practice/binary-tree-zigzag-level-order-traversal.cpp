//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/



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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        if(root) st1.push(root);
        
        while(!st1.empty() || !st2.empty()){
            vector<int> temp;
            while(!st1.empty()){
                TreeNode* node=st1.top(); st1.pop();
                temp.push_back(node->val);
                if(node->left) st2.push(node->left);
                if(node->right) st2.push(node->right);
            }
            if(!temp.empty()) result.push_back(temp);
            temp.resize(0);
            while(!st2.empty()){
                TreeNode* node=st2.top(); st2.pop();
                temp.push_back(node->val);
                if(node->right) st1.push(node->right);
                if(node->left) st1.push(node->left);
            }
            if(!temp.empty()) result.push_back(temp);
            temp.resize(0);
        }
        return result;
            
    }
};
