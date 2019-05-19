//https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> st;
        int flag=0;
        for(int i=0;i<S.length();i++){
            flag=0;  
            while(!st.empty() && st.top()==S[i]){
                st.pop();
                flag=1;
            }
            if(flag==0)
                st.push(S[i]);
        }
        
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
                
        return ans;    
        
    }
};
