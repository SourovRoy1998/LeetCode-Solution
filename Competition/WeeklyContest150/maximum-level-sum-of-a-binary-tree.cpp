//https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

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
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        int curr=0,level=1, maxima=root->val;
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()){
            curr++;
            int n=Q.size();
            int level_sum=0;
            for(int i=0;i<n;i++){
                TreeNode* temp=Q.front(); 
                level_sum+=temp->val;
                if(temp->left) Q.push(temp->left);
                if(temp->right) Q.push(temp->right);
                Q.pop();
            }
            if(level_sum>maxima){
                maxima=level_sum;
                level=curr;
            }
        }
        
        return level;
    }
};
