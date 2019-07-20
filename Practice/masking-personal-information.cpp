//https://leetcode.com/problems/masking-personal-information/

class Solution {
public:
    string normalise(string S){
        string res="";
        for(auto x:S) if(isdigit(x)) res+=x;
        return res;
    }
    
    string maskPII(string S) {
        string result="";
        if(isalpha(S[0])){
            result+=tolower(S[0]);
            int i=1;
            while(S[i]!='@') i++;
            result+="*****";
            result+=tolower(S[i-1]);
            while(i<S.length()) result+=tolower(S[i++]);
        }
        else{
            string s=normalise(S);
            if(s.length()>10){
                result+='+';
                for(int i=0;i<s.length()-10;i++) result+='*';
                result+='-';
            }
            result+=("***-***-"+s.substr(s.length()-4));
        }
        
        return result;
    }
};
