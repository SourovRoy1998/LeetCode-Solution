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


/*
class Solution:
    def findCircleNum(self, neighbours):
        def Find(x):
            if parent[x]!=x:
                parent[x]=Find(parent[x])
            return parent[x]
        def Union(x,y):
            parent[Find(x)]=Find(y)
            
        n,answer=len(neighbours),len(neighbours)
        parent=[0]*n
        for i in range(n):
            parent[i]=i
        for i in range(n):
            for j in range(n):
                if neighbours[i][j]==1 and Find(i)!=Find(j):
                    Union(i,j)
                    answer-=1
        return answer
*/
