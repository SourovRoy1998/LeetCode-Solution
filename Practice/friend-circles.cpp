//https://leetcode.com/problems/friend-circles/

class Solution {
public:
    int Find(int x){
        if(parent[x]!=x)
            parent[x]=Find(parent[x]);
        return parent[x];
    }
    
    void Union(int x, int y){
        parent[Find(x)]=Find(y);
    }
    
    
    vector<int> parent;
    int findCircleNum(vector<vector<int>>& M) {
        int n=M.size(),answer=M.size();
        parent.resize(n,0);
        for(int i=0;i<n;i++)
            parent[i]=i;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(M[i][j]==1 && Find(i)!=Find(j)){
                    Union(i,j); answer--;
                }
        return answer;
    }
};
