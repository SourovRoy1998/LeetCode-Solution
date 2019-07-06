//https://leetcode.com/contest/weekly-contest-110/problems/reorder-log-files/


class Solution {
public:
     static bool comp(string s1, string s2){
        int i=0,j=0;
        int m=s1.length(),n=s2.length();
        while(s1[i]!=' ') i++;
        while(s2[j]!=' ') j++;
        i++;j++;
        string sub1,sub2;
        sub1=s1.substr(i,m-i);
        sub2=s2.substr(j,m-j);
        if(sub1!=sub2) return sub1<sub2;
        
        return s1.substr(0,i)<s2.substr(0,j);
    }
    
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> result;
        vector<string> letter_logs;
        vector<string> digit_logs;
        
        for(auto x : logs){
            int i=0;
            while(x[i]!=' ') i++;
            if(isdigit(x[++i])) digit_logs.push_back(x);
            else letter_logs.push_back(x);   
        }
        
        sort(letter_logs.begin(),letter_logs.end(),comp);
        result.insert(result.end(),letter_logs.begin(),letter_logs.end());
        result.insert(result.end(),digit_logs.begin(),digit_logs.end());
        
        return result;
    }
};
