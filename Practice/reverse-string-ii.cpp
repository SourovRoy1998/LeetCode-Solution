//https://leetcode.com/problems/reverse-string-ii/


class Solution {
public:
    string reverseStr(string s, int k) {
        int n=s.length();
        string answer="";
        int i;
        for(i=0;i<(n/k)*k+1;i+=k){
            string str=s.substr(i,k);
            if((i/k)%2==0) reverse(str.begin(),str.end());
            answer+=str;
        }
        
        return answer;
    }
};












class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i=0;i<s.length();i+=2*k)
            reverse(s.begin()+i,min(s.end(),s.begin()+i+k));
        return s;
    }
};
