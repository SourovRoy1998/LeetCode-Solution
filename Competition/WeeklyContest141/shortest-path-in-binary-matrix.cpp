//Error
//https://leetcode.com/problems/shortest-path-in-binary-matrix/


class Solution {
public:
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> memoize(grid.size(),vector<int> (grid[0].size(),INT_MAX));
        if(grid[0][0]==1)
            return -1;
        
        memoize[0][0]=1;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0 && !(i==0 && j==0)){
                    int mini=INT_MAX;
                    if(i>0 && j>0)
                        mini=min(mini,memoize[i-1][j-1]);
                    if(j>0)
                        mini=min(mini,memoize[i][j-1]);
                    if(i>0)
                        mini=min(mini,memoize[i-1][j]);
                    if(i>0 && j<grid[0].size()-1)
                        mini=min(mini,memoize[i-1][j+1]);
                    if(mini!=INT_MAX)
                        memoize[i][j]=mini+1;
                }
            }
        }
        
    
        if(memoize[grid.size()-1][grid[0].size()-1]==INT_MAX)
            return -1;
        return memoize[grid.size()-1][grid[0].size()-1];
    }
};
