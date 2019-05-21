//https://leetcode.com/problems/rotate-string/

class Solution {
public:
    bool rotateString(string A, string B) {
        int n=A.length();
        if(B.length()!=n)
            return false;
        if(n==0)
            return true;
        for(int i=0;i<n;i++){
            int flag=true;
            for(int j=0;j<n;j++){
                if(B[(i+j)%n]!=A[j]){
                    flag=false;
                    break;
                }
            }
            if(flag)
                return true;
        }
        return false;;    
        
        
    }
};
