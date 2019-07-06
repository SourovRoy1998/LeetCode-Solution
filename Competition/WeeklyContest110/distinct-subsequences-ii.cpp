//https://leetcode.com/problems/distinct-subsequences-ii/discuss/284050/Python-O(N)-%22Dynamic-Programming-to-count%22
//https://leetcode.com/contest/weekly-contest-110/problems/distinct-subsequences-ii/

class Solution {
public:
    int distinctSubseqII(string S) {
        long long int n=S.length(),sum;
        long long int MOD=1000000007;
        vector<long long int> dp(n+1);
        dp[0]=1;dp[1]=1;
        for(int i=2;i<=n;i++){
            sum=1;
            for(int j=1;j<i;j++){
                sum=(sum+dp[j]);
                if(S[i-1]==S[j-1]) sum=sum-dp[j];
            }
            dp[i]=sum%MOD;
        }
        
        sum=0;
        for(int i=1;i<=n;i++)
            sum+=dp[i];
        return sum%MOD;
    }
};
