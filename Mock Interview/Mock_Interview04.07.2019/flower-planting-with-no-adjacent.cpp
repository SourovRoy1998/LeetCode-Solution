//https://leetcode.com/problems/flower-planting-with-no-adjacent/



class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        map<int,vector<int>> hmap;
        vector<bool> adj(5);
        for(auto x: paths){
            hmap[x[0]].push_back(x[1]);
            hmap[x[1]].push_back(x[0]);
        }
        
        vector<int>output(N,0);
        
       
        for(int i=0;i<N;i++){
            adj[0]=false;adj[1]=false;adj[2]=false;adj[3]=false;adj[4]=false;
            for(auto k: hmap[i+1])
                adj[output[k-1]]=true;
            for(int j=1;j<5;j++)
               if(adj[j]==false){
                    output[i]=j;break;
               }
        }
        
        return output;
        
    }
};
