//https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/

class Solution {
public:
    std::string reverseParentheses(std::string s) {
        int n=s.size();
        int begin=0, end=n-1;
        for(int i=0; i<n; i++){
            if(s[i] == '(')
                begin = i;
            if(s[i] == ')'){
                end = i;
                string temp = s.substr(begin + 1, end - begin - 1);
                reverse(temp.begin(),temp.end());
                return reverseParentheses(s.substr(0, begin) + temp + s.substr(end + 1));
             }
        }
        return s;
    }
};
