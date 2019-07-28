//https://leetcode.com/problems/largest-1-bordered-square/

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int result=0;
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> hor(m,vector<int>(n,0)); 
        vector<vector<int>> ver(m,vector<int>(n,0));
        
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j==0 && grid[i][j]==1) ver[i][j]=1;
                else if(j!=0 && grid[i][j]==1) ver[i][j]=ver[i][j-1]+1;
                
                if(i==0 && grid[i][j]==1) hor[i][j]=1;
                else if(i!=0 && grid[i][j]==1) hor[i][j]=hor[i-1][j]+1;
            }
        }
        
        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int sqr=min(ver[i][j],hor[i][j]);
                
                while(sqr>result){
                    if(ver[i-sqr+1][j]>=sqr && hor[i][j-sqr+1]>=sqr) result=sqr;
                    sqr--;
                }
            }
        }
        
        return result*result; 
        
    }
};
