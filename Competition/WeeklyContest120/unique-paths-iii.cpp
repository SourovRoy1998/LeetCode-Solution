//https://leetcode.com/problems/unique-paths-iii/

vector<vector<bool>> visited;

class Solution {
public:
    void backtrack(vector<vector<int>> grid, int row, int col, int cell_count, int& ans){
        if(cell_count==0 && grid[row][col]==2 ) {ans++; return;}
        else if(cell_count!=0 && grid[row][col]==2 ) {return;}
        
        visited[row][col]=true;
        
        if(row>0 && grid[row-1][col]!=-1 && !visited[row-1][col])
            backtrack(grid,row-1,col,cell_count-1,ans);
        
        if(col>0 && grid[row][col-1]!=-1 && !visited[row][col-1])
            backtrack(grid,row,col-1,cell_count-1,ans);
        
        if(row<grid.size()-1 && grid[row+1][col]!=-1 && !visited[row+1][col])
            backtrack(grid,row+1,col,cell_count-1,ans);
        
        if(col<grid[0].size()-1 && grid[row][col+1]!=-1 && !visited[row][col+1])
            backtrack(grid,row,col+1,cell_count-1,ans);
        
        visited[row][col]=false;
    }
    
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        visited.clear();
        visited.resize(grid.size(),vector<bool>(grid[0].size(),false));
        
        int row=0,col=0;
        int cell_count=1;
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){row=i;col=j;}
                if(grid[i][j]==0){cell_count++;}
            }
        }
        backtrack(grid,row,col,cell_count,ans);
        return ans;
    }
};
