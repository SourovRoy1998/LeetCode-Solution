//https://leetcode.com/problems/generate-parentheses/


class Solution {
public:
    void generate(set<string>& s, int n, string pattern, int currently_open, int already_closed){
        if(pattern.length()==2*n)
            s.insert(pattern);
        else{
            if(currently_open+already_closed<n)
                generate(s,n,pattern+'(',currently_open+1,already_closed);
    
            if(currently_open>0)
                generate(s,n,pattern+')',currently_open-1,already_closed+1);
        }
        
    }
    
    
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        set<string> s;
        
        generate(s,n,"(",1,0);
        for(auto x:s)
            result.push_back(x);
        return result;
        
    }
    
    
};
