//https://leetcode.com/problems/add-strings/


class Solution {
public:
    string addStrings(string num1, string num2) {
        int m=num1.length();
        int n=num2.length();
        int i=m-1,j=n-1;
        string ans="";
        int carry=0,sum=0;
        
        while(i>=0 || j>=0){
            sum=carry;
            if(i>=0)
                sum+=((int)(num1[i--])-48);
            if(j>=0)
                sum+=((int)(num2[j--])-48);
            ans+=to_string(sum%10);
            carry=sum/10;
        }
        if(carry)
            ans+=to_string(carry);
            
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};
