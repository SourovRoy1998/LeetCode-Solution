//https://leetcode.com/problems/invalid-transactions/

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> answer;
        unordered_set<string> result;
        unordered_map<string, vector<vector<string>>> hmap;
        for(auto t : transactions){
            istringstream ss(t);
            int i=0;
            vector<string> s(4,""); 
            while(getline(ss,s[i++],','));
            if(stoi(s[2])>1000) result.insert(t);
            for(auto j : hmap[s[0]]){
                if(s[3]!=j[3] && abs(stoi(s[1])-stoi(j[1]))<=60){
                    result.insert(j[0]+","+j[1]+","+j[2]+","+j[3]);
                    result.insert(t);
                }
                    
            }
            hmap[s[0]].push_back({s[0],s[1],s[2],s[3]});
        }
        for(auto k : result)
            answer.push_back(k);
        return answer;
    }
};
