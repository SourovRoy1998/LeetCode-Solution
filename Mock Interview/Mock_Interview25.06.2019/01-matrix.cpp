//https://leetcode.com/problems/01-matrix/


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int mini;
        
        vector<vector<int>> memoize(m,vector<int> (n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mini=INT_MAX-1;
                if(matrix[i][j]){
                    if(i>0)
                        mini=memoize[i-1][j];
                    if(j>0)
                        mini=min(memoize[i][j-1],mini);
                    if(mini!=INT_MAX)
                        memoize[i][j]=mini+1;
                    else
                        memoize[i][j]=mini;
                }
            }
        }
        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(matrix[i][j]){
                    if(i<(m-1))
                        memoize[i][j]=min(memoize[i+1][j],memoize[i][j]-1)+1;
                    if(j<(n-1))
                        memoize[i][j]=min(memoize[i][j+1],memoize[i][j]-1)+1;
                }
            }
        }
        return memoize;
    }
};
