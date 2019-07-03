//https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends/

class Solution {
public:
    int parent[101];
    int find(int x){
        if(x!=parent[x]){
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }
    
    int earliestAcq(vector<vector<int>>& logs, int N) {
        sort(logs.begin(),logs.end());
        for(int i=0;i<=N;i++)
            parent[i]=i;
        int count=1;
        for(auto x : logs){
            int p1=find(x[1]),p2=find(x[2]);
            if(p1!=p2){
                parent[p2]=parent[p1];
                count++;
                if(count==N) return x[0];
            }
        }
        return -1;
    }
};
