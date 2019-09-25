//https://leetcode.com/problems/happy-number/

class Solution {
public:
    
    int digitsumsq(int n){
        int ans=0;
        while(n!=0){
            ans+=((n%10)*(n%10));
            n/=10;
        }
        return ans;
    }
    
    bool isHappy(int n) {
        int slow=n,fast=n;
        do{
            slow=digitsumsq(slow);
            fast=digitsumsq(digitsumsq(fast));
        }
        while(slow!=fast);
        if(slow==1) return true;
        else return false;
    }
};
