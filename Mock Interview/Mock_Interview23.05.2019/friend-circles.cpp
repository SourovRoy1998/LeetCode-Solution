//https://leetcode.com/problems/friend-circles/

class Solution {
public:
    int find(vector<int>& parent, int p) 
    {
        return parent[p]==-1 ? p : find(parent, parent[p]);
    }
    
    int findCircleNum(vector<vector<int>>& M) 
    {
        vector<int> parent(M.size(),-1);
        int N = M.size();
        
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(M[i][j])
                {
                    int u = find(parent,i);
                    int v = find(parent,j);
                    if(u!=v) parent[v] = u;
                }
            }
        }
        return count(parent.begin(), parent.end(), -1);
    }
};
