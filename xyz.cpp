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
    void left(TreeNode* root, map<int,pair<int,int>>& hmap, int& curr_height, int width){
        if(root==NULL)
            return;
        if(root->left)
            left(root->left,hmap,cur_height+1,width-1);
        else
            left(root-right,hmap,curr_height+1,width+1);
        hmap[curr_height].first=width;
    }
    
    int widthOfBinaryTree(TreeNode* root) {
        map<int,pair<int,int>> hmap;
        hmap[0]={1,0}
        int curr_height=0;
        left(root,hmap,curr_height,0);
        
    }
};
