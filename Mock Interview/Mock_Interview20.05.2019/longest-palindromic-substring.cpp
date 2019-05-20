//https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty())
            return s;
        int n=s.length();
        bool memoize[n][n]={{false}};
        int max_len=1;
        int index=0;
        
        for(int i=0;i<n;i++)
            memoize[i][i]=true;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                memoize[i][i+1]=true;
                max_len=2;
                index=i;
            }
        }
        
        for(int curr_len=3;curr_len<=n;curr_len++){
            for(int i=0;i<n-curr_len+1;i++){
                if(s[i]==s[i+curr_len-1] && memoize[i+1][i+curr_len-2]){
                    memoize[i][i+curr_len-1]=true;
                    max_len=curr_len;
                    index=i;
                }
            }
        }
        
        return s.substr(index,max_len);
    }
};
