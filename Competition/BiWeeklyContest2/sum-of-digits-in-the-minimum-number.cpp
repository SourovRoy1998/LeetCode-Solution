//https://leetcode.com/contest/biweekly-contest-2/problems/sum-of-digits-in-the-minimum-number/

class Solution {
public:
    int sumOfDigits(vector<int>& A) {
        int mini=A[0];
        for(int i=0;i<A.size();i++)
            mini=min(mini,A[i]);
        int sum=1;
        while(mini){
            sum+=mini%10;
            mini=mini/10;
        }
        
        return sum%2;
    }
};
