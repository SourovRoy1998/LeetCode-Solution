//https://leetcode.com/problems/surface-area-of-3d-shapes/

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n=grid.size(), result=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                if(grid[i][j])result+=4*grid[i][j]+2;
                if(i) result-=min(grid[i][j],grid[i-1][j])*2;
                if(j) result-=min(grid[i][j],grid[i][j-1])*2;
            }
        return result;
    }
};
