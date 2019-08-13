//https://leetcode.com/problems/cousins-in-binary-tree/

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
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        vector<vector<int>> result;
        queue<Node*> Q;
        Q.push(root);
        vector<int> temp;
        
        while(!Q.empty()){
            int n=Q.size(); temp={};
            for(int i=0;i<n;i++){
                Node* node=Q.front();Q.pop();
                temp.push_back(node->val);
                for(auto x : node->children)
                    if(x) Q.push(x);
            }
            result.push_back(temp);
        }
        
        return result;
    }
};
