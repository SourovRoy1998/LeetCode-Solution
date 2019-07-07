//https://leetcode.com/problems/delete-nodes-and-return-forest/


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
    TreeNode* Del(TreeNode* root, set<int>& s, vector<TreeNode*>& result) {
        if(root==NULL) return NULL;
        
        //Recursive Postorder Traversal
        root->left=Del(root->left,s,result);  
        root->right=Del(root->right,s,result);
        
        //After post order traversal, if any current node requires to
        //be eliminated, then definitely left and right remaining subtrees
        //will be in our result array. In such case, the entire
        //subtree at current node will not appear in the remaining tree.
        //So we return NULL.  
        if(s.find(root->val)!=s.end()){
            if(root->left)
                result.push_back(root->left);
            if(root->right)
                result.push_back(root->right);
            return NULL;
        }
        
        //If nothing happens, then we return the root to build the remaining tree;
        return root;
    }
    
    
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(root==NULL) return {};
        
        //Keeping the values of 'to_delete' in a set 's' for faster look up;
        set<int> s;  
        for(auto x: to_delete) s.insert(x); 
    
        vector<TreeNode*> result;
        
        //After eliminating all the to_delete nodes, there will be a backbone 
        //tree(i.e. a subtree of the original tree). Let call it remaining tree;  
        TreeNode* remaining_tree;
        remaining_tree=Del(root,s,result); 
        if(remaining_tree)
            result.push_back(remaining_tree);
        
        return result;
        
    }
};
