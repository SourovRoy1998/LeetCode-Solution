//https://leetcode.com/problems/can-make-palindrome-from-substring/


class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n=s.length();
        vector<vector<int>> Count;
        vector<int> curr(26,0);
        Count.push_back(curr);
        for(int i=0;i<n;i++){
            curr[s[i]-'a']++;
            Count.push_back(curr);
        }
        
        vector<bool> result;
        for(auto x:queries){
            int c=0;
            for(int i=0;i<26;i++){
                if((Count[x[1]+1][i]-Count[x[0]][i])%2==1)
                    c++;
            }
            if(c/2>x[2]) result.push_back(false);
            else result.push_back(true);
        }
        
        return result;
        
    }
};


/*
class Solution:
    def canMakePaliQueries(self, s, queries):
        n=len(s)
        Count=[]
        curr=[0]*26
        Count.append(curr.copy())
        for i in range(n):
            curr[ord(s[i])-ord("a")]+=1
            Count.append(curr.copy())
        result=[]
        
        
        for x in queries:
            c=0
            for i in range(26):
                if (Count[x[1]+1][i]-Count[x[0]][i])%2==1:
                    c+=1
            result.append(`c//2)
        return result
        
*/
