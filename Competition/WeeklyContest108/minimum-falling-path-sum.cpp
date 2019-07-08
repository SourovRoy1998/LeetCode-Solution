//https://leetcode.com/problems/minimum-falling-path-sum/
//DP Solution
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int m=A.size(),n=A[0].size();
        vector<vector<int>> memoize(m,vector<int>(n,INT_MAX));
        int ans=INT_MAX;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0) memoize[i][j]=A[i][j];
                else{
                    for(int k=max(0,j-1);k<=min(n-1,j+1);k++)
                        memoize[i][j]=min(memoize[i-1][k]+A[i][j],memoize[i][j]);                
                }
                
                if(i==(m-1)) ans=min(ans,memoize[i][j]);
            }
        }
        
        return ans;
    }
};



//Backtracking TLE

class Solution {
public:
    void minFall(vector<vector<int>>& A, vector<vector<bool>>& visited, int& smallest_sum,int sum, int row, int prev){
        int m=A.size(),n=A[0].size();
        if(row==m){smallest_sum=min(smallest_sum,sum); return;}
        
        for(int i=0;i<n;i++){
            if(prev==-1 || abs(i-prev)<=1){
                visited[row][i]=true;
                minFall(A,visited,smallest_sum,sum+A[row][i],row+1,i);
                visited[row][i]=false;
            }
        }
    }
    
    
    int minFallingPathSum(vector<vector<int>>& A) {
        int m=A.size(),n=A[0].size();
        vector<vector<bool>> visited(m,vector<bool> (n,false));
        int smallest_sum=INT_MAX;
        
        minFall(A,visited,smallest_sum,0,0,-1);
        
        return smallest_sum;
    }
};
