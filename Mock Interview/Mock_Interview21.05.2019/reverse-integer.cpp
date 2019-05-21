//https://leetcode.com/problems/reverse-integer/

class Solution {
public:
    int reverse(int x) {
        long long y=(long long)x;
        bool minus=false;
        if(y<0){
            minus=true;
            y=abs(y);
        }
            
        string str=to_string(y);
        std::reverse(str.begin(), str.end());
        long long l=stoll(str);
        if(l>INT_MAX)
            return 0;
        if(minus==true)
            return -l;
        return l;
    }
};
