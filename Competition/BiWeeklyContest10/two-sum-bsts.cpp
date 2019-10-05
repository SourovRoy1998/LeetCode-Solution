//https://leetcode.com/contest/biweekly-contest-10/problems/two-sum-bsts/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int countPairs(TreeNode* root1, TreeNode* root2, int x) 
{ 
    // if either of the tree is empty 
    if (root1 == NULL || root2 == NULL) 
        return 0; 
  
    // stack 'st1' used for the inorder 
    // traversal of BST 1 
    // stack 'st2' used for the reverse 
    // inorder traversal of BST 2 
    stack<TreeNode*> st1, st2; 
    TreeNode* top1, *top2; 
  
    int count = 0; 
  
    // the loop will break when either of two 
    // traversals gets completed 
    while (1) { 
  
        // to find next node in inorder 
        // traversal of BST 1 
        while (root1 != NULL) { 
            st1.push(root1); 
            root1 = root1->left; 
        } 
  
        // to find next node in reverse 
        // inorder traversal of BST 2 
        while (root2 != NULL) { 
            st2.push(root2); 
            root2 = root2->right; 
        } 
  
        // if either gets empty then corresponding 
        // tree traversal is completed 
        if (st1.empty() || st2.empty()) 
            break; 
  
        top1 = st1.top(); 
        top2 = st2.top(); 
  
        // if the sum of the node's is equal to 'x' 
        if ((top1->val + top2->val) == x) { 
            // increment count 
            count++; 
  
            // pop nodes from the respective stacks 
            st1.pop(); 
            st2.pop(); 
  
            // insert next possible node in the 
            // respective stacks 
            root1 = top1->right; 
            root2 = top2->left; 
        } 
  
        // move to next possible node in the 
        // inoder traversal of BST 1 
        else if ((top1->val + top2->val) < x) { 
            st1.pop(); 
            root1 = top1->right; 
        } 
  
        // move to next possible node in the 
        // reverse inoder traversal of BST 2 
        else { 
            st2.pop(); 
            root2 = top2->left; 
        } 
    } 
  
    // required count of pairs 
    return count; 
} 


class Solution {
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        if(countPairs(root1,root2,target)) return true;
        return false;
    }
};
