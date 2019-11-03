//https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int n=s1.length();
        int x1=0, y1=0;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                if(s1[i]=='x') x1++;
                else y1++;
            }
        }
        
        if((x1+y1)%2==1) return -1;
        return x1/2+y1/2+x1%2+y1%2;
        
    }
};
