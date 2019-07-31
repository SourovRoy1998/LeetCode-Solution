//https://leetcode.com/problems/next-greater-element-iii/

//Using library function
class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);
        next_permutation(s.begin(),s.end());
        long long num=stoll(s);
        return (num>INT_MAX || num<=n) ? -1:num;
    }
};
