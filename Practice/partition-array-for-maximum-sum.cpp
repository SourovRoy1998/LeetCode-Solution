//https://leetcode.com/problems/partition-array-for-maximum-sum/


class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int n=A.size();
        vector<int> dp(n,0);
        
        for(int i=0;i<n;i++){
            int currMax=0;
            for(int x=1; x<=K && i-x+1>=0;x++){
                currMax=max(currMax, A[i-x+1]);
                dp[i]=max(dp[i],(i>=x?dp[i-x]:0)+x*currMax);
            }
        }
        
        return dp[n-1];
    }
};
