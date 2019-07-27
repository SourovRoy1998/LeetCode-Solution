//https://leetcode.com/contest/biweekly-contest-5/problems/armstrong-number/


class Solution {
public:
    bool isArmstrong(int N) {
        string s=to_string(N);
        int n=s.length(),result=0;
        int sum=0;
        for(auto x : s){
            result+=pow((x-'0'),n);
            if(result>N) return false;
        }
        
        return result==N;
        
    }
};
