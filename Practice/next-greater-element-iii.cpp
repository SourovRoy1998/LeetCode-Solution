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


//My Implementation
class Solution {
public:
    void next_permutation(string& s){
        int n=s.length();
        int i=n-2;
        while(i>=0 && s[i]>=s[i+1]) i--;
        if(i==-1) return;
        int j=i;
        while(j<n-1 && s[j+1]>s[i]) j++;
        swap(s[i],s[j]);
        reverse(s.begin()+i+1, s.end());
    }
    
    
    int nextGreaterElement(int n) {
        string s=to_string(n);
        next_permutation(s);
        long long num=stoll(s);
        return (num>INT_MAX || num<=n) ? -1:num;
    }
};
