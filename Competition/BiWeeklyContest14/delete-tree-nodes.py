##https://leetcode.com/problems/delete-tree-nodes/

class Solution:
    def deleteTreeNodes(self, n, parent, value):
        sons = {i: set() for i in range(n)}
        for i, p in enumerate(parent):
            if i: sons[p].add(i)

        def dfs(x):
            total, count = value[x], 1
            for y in sons[x]:
                t, c = dfs(y)
                total += t
                count += c if t else 0
            return total, count if total else 0
        return dfs(0)[1]
    
    
    
    '''
    class Solution {
public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        vector<int> result(nodes);
        for(int i=nodes-1;i>0;i--){
            value[parent[i]]+=value[i];
            result[parent[i]]+=value[i]?result[i]+1:0;
        }
        return value[0]?result[0]+1:0;
    }
};
'''
