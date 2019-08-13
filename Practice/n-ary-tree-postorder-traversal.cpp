//https://leetcode.com/problems/n-ary-tree-postorder-traversal/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    void helper(Node* root,vector<int>& result){
        if(!root) return;
        for(auto x : root->children)
            helper(x,result);
        result.push_back(root->val);
    }
    
    vector<int> postorder(Node* root) {
        if(!root) return {};
        vector<int> result;
        helper(root,result);
        return result;
    }
};
