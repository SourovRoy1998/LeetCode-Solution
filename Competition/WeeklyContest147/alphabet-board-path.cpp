//https://leetcode.com/problems/alphabet-board-path/

class Solution {
public:
    string alphabetBoardPath(string target) {
        int i=0,j=0;
        string result="";
        for(auto x : target){
            int p=(x-'a')/5,q=(x-'a')%5;
            
            int r=i-p,s=j-q;
            
            if(i!=5){
                if(s>0) while(s--) result+='L';
                else while(s++) result+='R';
                if(r>0) while(r--) result+='U';
                else while(r++) result+='D';
            }
            else{
                if(r>0) while(r--) result+='U';
                else while(r++) result+='D';
                if(s>0) while(s--) result+='L';
                else while(s++) result+='R';
            }
            result+='!';
            i=p;j=q;
                
        }
        
        return result;
        
    }
};
