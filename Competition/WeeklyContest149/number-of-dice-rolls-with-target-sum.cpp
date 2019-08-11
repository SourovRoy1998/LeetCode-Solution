//https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

class Solution {
public:
    int mod=1000000007;
    int numRollsToTarget(int n, int m, int x) {
        vector<vector<int>> memoize(n+1,vector<int>(x+1,0));
    
        for (int j = 1; j<=m && j<=x; j++) 
            memoize[1][j] = 1; 
        
        for(int i=2;i<=n;i++){
            for(int j=1;j<=x;j++){
                for(int k=1;k<=m && k<j ;k++){
                    memoize[i][j]=(memoize[i][j]+memoize[i-1][j-k])%mod;
                }
            }
        }
        
        return memoize[n][x]%mod;
    }
};
