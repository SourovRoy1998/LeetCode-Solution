//https://leetcode.com/problems/unique-email-addresses/

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> s;
        for(auto addr : emails){
            string temp="";
            bool a_found=false,plus_found=false;
            
            for(int i=0;i<addr.size();i++){
                if(addr[i]=='@') a_found=true;
                else if(a_found==false && addr[i]=='.') continue;
                else if(a_found==false && addr[i]=='+') {while(addr[i+1]!='@') i++;continue;}
                temp+=addr[i];
            }
            s.insert(temp);
        }
        
        return s.size();
    }
};
