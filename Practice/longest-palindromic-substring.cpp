//https://leetcode.com/problems/longest-palindromic-substring/



class Solution {
public:
    string longestPalindrome(string s) {
        if(s=="") return s;
        int max_len=1,index=0,n=s.length();
        vector<vector<bool>> memoize(n,vector<bool>(n,false));
        
        for(int i=0;i<n;i++)
            memoize[i][i]=true;
        for(int i=0;i<n-1;i++)
            if(s[i]==s[i+1]){
                max_len=2;
                index=i;
                memoize[i][i+1]=true;
            }
        
        for(int curr_len=3;curr_len<=n;curr_len++){
            for(int i=0;i<n-curr_len+1;i++){
                if(s[i]==s[i+curr_len-1] && memoize[i+1][i+curr_len-2]==true){
                    max_len=curr_len;
                    index=i;
                    memoize[i][i+curr_len-1]=true;
                }
                    
            }
        }
        
        return s.substr(index,max_len);
    }
};
