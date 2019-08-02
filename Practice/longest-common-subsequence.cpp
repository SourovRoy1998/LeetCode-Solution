//https://leetcode.com/problems/longest-common-subsequence/



//O(m*n) time and O(m*n) space solution
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(),n=text2.size();
        vector<vector<int>> memoize(m+1, vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1]==text2[j-1]) memoize[i][j]=memoize[i-1][j-1]+1;
                else memoize[i][j]=max(memoize[i-1][j],memoize[i][j-1]);
            }
        }
        
        return memoize[m][n];
        
    }
};



//O(m*n) time and O(m) space solution 


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(),n=text2.size();
        vector<vector<int>> memoize(m+1, vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if (text1[i - 1] == text2[j - 1]) memoize[i % 2][j] = memoize[(i -1) % 2][j - 1] + 1;
                 else memoize[i % 2][j] = max(memoize[(i - 1) % 2][j], memoize[i % 2][j - 1]);
            }
        }
        
        return memoize[m%2][n];
        
    }
};
