//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/


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
    TreeNode* AtoB(vector<int> nums, int left, int right){
        if(left>right) return NULL;
        int mid=(left+right)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left=AtoB(nums,left,mid-1);
        root->right=AtoB(nums,mid+1,right);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return AtoB(nums,0,nums.size()-1);
    }
};
