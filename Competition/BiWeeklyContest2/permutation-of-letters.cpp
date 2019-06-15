//https://leetcode.com/contest/biweekly-contest-2/problems/permutation-of-letters/

class Solution {
public:
    vector<string> perm(vector<vector<string>> vec,int start, int end){
        if(start==end)
            return vec[start];
        vector<string> res;
        
        for(auto x : vec[start]){
            for(auto y : perm(vec,start+1,end)){
                res.push_back(x+y);
            }
        }
        return res;
    }
    
    
    vector<string> permute(string S) {
        vector<vector<string>> vec;
        for(int i=0;i<S.length();i++){
            
            if(S[i]=='{'){
                vector<string> temp;
                while(S[i]!='}'){
                    if(S[i]!=',' && S[i]!='{'){
                        string s(1,S[i]);
                        temp.push_back(s);
                    }
                    i++;
                }
                vec.push_back(temp);    
            }
            else if (S[i]!=','){
                vector<string> temp;
                string s(1,S[i]);
                temp.push_back(s);
                vec.push_back(temp);
            }  
        }
        
        
        int n=vec.size();
        for(int i=0;i<n;i++)
            sort(vec[i].begin(),vec[i].end());
        return perm(vec,0,n-1);
    }
};
