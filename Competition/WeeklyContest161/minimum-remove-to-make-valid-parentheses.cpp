//https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/


class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string result1="", result2="";
        int n=s.length(), count=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){ 
                count++;
                result1+=s[i];
            }

            else if(s[i]==')'){
                if(count>0){ result1+=s[i]; count--;}
                count=max(count,0);
            }
            
            else result1+=s[i];
        }
        
        
        if(count<=0) return result1;
        
        count=0;n=result1.size();
        for(int i=n-1;i>=0;i--){
            if(result1[i]==')'){ 
                count++;
                result2+=result1[i];
            }

            else if(result1[i]=='('){
                if(count>0){ result2+=result1[i]; count--;}
                count=max(count,0);
            }
            
            else result2+=result1[i];
        }
        
        reverse(result2.begin(), result2.end());
        return result2;
        
        
    }
};
