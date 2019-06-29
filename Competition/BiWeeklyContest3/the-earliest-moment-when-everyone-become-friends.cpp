//https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends/


// Do it Tomorrow...


class Solution {
    int find(int i, vector<int>& par) {
        if (par[i] == -1) return i;
        par[i] = find(par[i], par);
        return par[i];
    }
    
    void _union(int i, int j, vector<int>& par, vector<int>& rank) {
        if (rank[i] >= rank[j]) {
            par[j] = i;
            if (rank[i] == rank[j])
                rank[i]++;
        } else {
            par[i] = j;
        }
    }
    
public:
    int earliestAcq(vector<vector<int>>& logs, int N) {
        vector<int> par(N, -1);
        vector<int> rank(N, 0);
        
        sort(logs.begin(), logs.end(), [](auto& a, auto& b) { return a[0] < b[0];});
        
        for (auto& e : logs) {
            int u = e[1], v = e[2];
            int pu = find(u, par), pv = find(v, par);
            if (pu != pv) {
                N--;
                _union(pu, pv, par, rank);
            }
            if (N == 1) return e[0];
        }
        return -1;
    }
};


/*

class Solution:
    def earliestAcq(self, logs: List[List[int]], n: int) -> int:
        memo = {i:i for i in range(n)}
        rest = n - 1
        logs.sort(key = lambda x:x[0])
        
        def find(i):
            if i != memo[i]:
                memo[i] = find(memo[i])
            return memo[i]
        
        def union(x,y):
            xx = find(x)
            yy = find(y)
            if xx == yy:
                return False
            memo[xx] = memo[yy]
            return True
            
        for t,i,j in logs:
            rest -= union(i,j)
            if not rest:
                return t
        return -1
        
        
*/        
