//https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int day=-1,count=0;
        queue<vector<int>> Q;
        vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
        set<vector<int>>visited;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) count++;
                if(grid[i][j]==2){ Q.push({i,j,0}); visited.insert({i,j});}
            }
        }
       if(count==0) return 0; 
       while(!Q.empty()){
            vector<int> elem=Q.front();
            Q.pop();
            int x=elem[0],y=elem[1];
            day=elem[2];
            for(auto e : dir){
                int dx=e[0];
                int dy=e[1];
                if(x+dx<m && y+dy<n && x+dx>=0 && y+dy>=0 && grid[x+dx][y+dy] && visited.find({x+dx,y+dy})==visited.end()){
                    count--;
                    if(count==0) return day+1;
                    visited.insert({x+dx,y+dy});
                    Q.push({x+dx,y+dy,day+1});
                }
            }
        }
        if(count) return -1;
        return day;
    } 
};




//Python3
/*
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        m,n=len(grid),len(grid[0])
        time, count=0,0
        Q=collections.deque()
        direction=[[0,1],[1,0],[0,-1],[-1,0]]
        
        for i in range(m):
            for j in range(n):
                if grid[i][j]==1:
                    count+=1
                elif grid[i][j]==2:
                    Q.append([i,j,0])
        if(count==0):
            return 0
        
        while Q:
            i,j,k=Q.popleft()
            for dx,dy in direction:
                if m>i+dx>=0 and n>j+dy>=0 and grid[i+dx][j+dy]==1:
                    grid[i+dx][j+dy]=2
                    Q.append([i+dx,j+dy,k+1])
                    time=k+1
                    count-=1
                    if count==0:
                        return time
        return -1
            
*/
