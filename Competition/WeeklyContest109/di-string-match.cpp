//https://leetcode.com/problems/di-string-match/

class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> result(S.length()+1,0);
        int maxi=S.length(),mini=0;
        
        for(int i=0;i<S.length();i++){
            if(S[i]=='I'){result[i]=mini;mini++;}
            else if(S[i]=='D'){result[i]=maxi;maxi--;}
        }
        result[S.length()]=mini;
            
        return result;
    }
};
