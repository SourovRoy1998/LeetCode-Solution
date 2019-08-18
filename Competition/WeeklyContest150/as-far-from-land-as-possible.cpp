//https://leetcode.com/problems/as-far-from-land-as-possible/


class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int answer=0,distance=0,water=0;
        queue<vector<int>> Q;
        vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) water++;
                if(grid[i][j]==1) Q.push({i,j});
            } 
        }
        if(water==0 || Q.empty()) return -1;
        
        while(!Q.empty()){
            int size=Q.size(); distance++;
            for(int i=0;i<size;i++){
                vector<int> temp=Q.front(); Q.pop();
                for(auto d : dir){
                    int x=d[0]+temp[0], y=d[1]+temp[1];
                    if(x>=0 && x<m && y>=0 && y<n && grid[x][y]==0){
                        answer=distance;
                        grid[x][y]=1;
                        Q.push({x,y});
                    }
                }
            }
        }
        
        return answer;
    }
};
