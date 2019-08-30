//https://leetcode.com/problems/restore-ip-addresses/

class Solution {
public:  
    vector<string> restoreIpAddresses(string s, int dot=3) {
        vector<string> result;int n=s.length();
        if(dot==0){
            if(n>1 && s[0]=='0') return {};
            if(n>=1 && n<=3 && stoi(s)<=255) return {s};
            return {};
        }
        for(int i=1;i<=min(3,n);i++){
            for(auto x : restoreIpAddresses(s.substr(i,n-i),dot-1)){
                string str=s.substr(0,i);
                if(str[0]=='0' && str.length()>1) continue;
                if(stoi(str)<=255 && !x.empty())
                    result.push_back(str+"."+x);
            }
        }
        return result;
    }
};
