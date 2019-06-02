//https://leetcode.com/problems/greatest-common-divisor-of-strings/

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int m=str1.size();
        int n=str2.size();
        int p=min(m,n);
        int gcd_len=0;
        for(int i=1;i<=p;i++){
            bool found=true;
            for(int j=0;j<str1.size();j++)
                if(str1[j]!=str1[j%i]){
                    found=false;
                    break;
                }
            for(int j=0;j<str2.size();j++)
                if(str2[j]!=str1[j%i]){
                    found=false;
                    break;
                }
            if(found==true && m%i==0 && n%i==0)
                gcd_len=i;
        }
        return str1.substr(0,gcd_len);
            
        
        
    }
};
