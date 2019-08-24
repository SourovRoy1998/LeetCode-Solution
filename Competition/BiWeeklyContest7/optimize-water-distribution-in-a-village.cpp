//https://leetcode.com/problems/optimize-water-distribution-in-a-village/

class Solution {
public:
    vector<int> parent;
    int Find(int x){
        if(parent[x]!=x)
            parent[x]=Find(parent[x]);
        return parent[x];
    }
    
    void Union(int x, int y){
        parent[Find(x)]=Find(y);
    }
    
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        for(int i=0;i<=n;i++) parent.push_back(i);
        vector<vector<int>> edges;
        for(int i=1;i<=n;i++) edges.push_back({wells[i-1],0,i});
        for(auto x : pipes) edges.push_back({x[2],x[0],x[1]});
        sort(edges.begin(),edges.end());
        int result=0;
        
        for(auto x : edges){
            if(Find(x[1])!=Find(x[2])){
                Union(x[1],x[2]);
                result+=x[0];
                n--;
            }
            if(n==0) return result;
        }
        return -1;  
    }
};

    
    
    
/*
class Solution:
    def minCostToSupplyWater(self, n, wells, pipes):
        UF = {i: i for i in xrange(n + 1)}

        def find(x):
            if x != UF[x]:
                UF[x] = find(UF[x])
            return UF[x]

        def union(x, y):
            UF[find(x)] = find(y)

        w = [[c, 0, i] for i, c in enumerate(wells, 1)]
        p = [[c, i, j] for i, j, c in pipes]
        res = 0

        for c, i, j in sorted(w + p):
            if find(i) != find(j):
                union(i, j)
                res += c
                n -= 1
            if n == 0:
                return res
        return -1
        
*/
