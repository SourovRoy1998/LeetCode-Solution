//https://leetcode.com/problems/maximum-width-of-binary-tree/
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
    
    void fillLevels(TreeNode *root, std::unordered_map<int, std::pair<unsigned int,unsigned int> > &map, int level, unsigned int nodeNumber)
    {
        if (root == NULL)
        {
            return;
        }
        else
        {
            if (map.find(level) == map.end())
            {
                map[level].first = nodeNumber;
                map[level].second = nodeNumber;
            }
            else
            {
                map[level].first = std::min(map[level].first, nodeNumber);
                map[level].second = std::max(map[level].second, nodeNumber); 
            }
            fillLevels(root->left, map, level + 1, nodeNumber * 2);
            fillLevels(root->right, map, level + 1, nodeNumber * 2 + 1);
            return;
        }
    }
    
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL)
        {
            return 0;
        }
        unsigned int maxWidth = 1;
        std::unordered_map<int, std::pair<unsigned int, unsigned int> > map;
        fillLevels(root, map, 0, 1);
        for (auto &m : map)
        {
            std::pair<unsigned int, unsigned int> *p = &(m.second);
            unsigned int nodeNumberLeft = p->first;
            unsigned int nodeNumberRight = p->second;
            maxWidth = std::max(maxWidth, nodeNumberRight - nodeNumberLeft + 1);    
        }
        return maxWidth;  
    }
};
