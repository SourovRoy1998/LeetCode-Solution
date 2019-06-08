//https://leetcode.com/problems/reorder-log-files/


class Solution {
public:
    static bool comp(string s1,string s2){
        int i=0,j=0;
        while(s1[i]!=' ')
            i++;
        while(s2[j]!=' ')
            j++;
        i++;j++;
        while(i<s1.length() && j<s2.length() && s1[i]==s2[j]){
            i++;j++;
        }
        if(i==s1.length() || j==s2.length())
            return s1[0]<s2[0];
        return s1[i]<s2[j];
    }
    
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digitLogs;
        vector<string> alphaLogs;
        for(auto x: logs){
            int i=0;
            while(x[i]!=' ')
                i++;
            if(!isalpha(x[++i]))
                digitLogs.push_back(x);
            else
                alphaLogs.push_back(x);
        }
        
        sort(alphaLogs.begin(),alphaLogs.end(),comp);
        
        alphaLogs.insert(alphaLogs.end(),digitLogs.begin(),digitLogs.end());
        
        return alphaLogs;
        
    }
};
