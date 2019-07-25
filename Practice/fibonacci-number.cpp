//https://leetcode.com/problems/fibonacci-number/

class Solution {
public:
    unordered_map<int,int> fi;
    Solution(){fi[0]=0,fi[1]=1;}
    int fib(int N) {
        if(fi.find(N)!=fi.end()) return fi[N];
        fi[N]=fib(N-1)+fib(N-2);
        return fi[N];
    }
};
