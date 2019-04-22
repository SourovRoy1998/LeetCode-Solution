//https://leetcode.com/problems/license-key-formatting/

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int count=0;
        string result="";
        for(int i=S.length()-1;i>=0;i--){
            if(S[i]=='-')
                continue;
            count++;
            if(isalpha(S[i]))
                result+=toupper(S[i]);
            else
                result+=S[i];
            if(count==K && i!=0){
                result+="-";
                count=0;
            }
        }    
        reverse(result.begin(),result.end());
        while(result[0]=='-')
            result.erase(result.begin());
        return result;
    }
};
