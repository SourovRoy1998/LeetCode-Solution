//https://leetcode.com/problems/unique-email-addresses/

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> s;
        for(auto x: emails){
            string str="";
            int i;
            for(i=0;i<x.length();i++){
                if(x[i]=='@' || x[i]=='+')
                    break;
                if(x[i]=='.')
                    continue;
                str+=x[i];
            }
            while(x[i]!='@')
                i++;
            for(;i<x.size();i++)
                str+=x[i];
            s.insert(str);
        }
        return s.size();
    }
};
