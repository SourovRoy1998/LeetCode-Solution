//https://leetcode.com/problems/find-common-characters/

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        if(A.size()==0) return {};
        vector<vector<int>> vec(A.size(), vector<int>(26,0));
        vector<string> result;
        for(int i=0;i<A.size();i++){
            for(auto x : A[i])
                vec[i][x-'a']++;
        }
        for(int i=0;i<26;i++){
            int mini=INT_MAX;
            for(int j=0;j<A.size();j++)
                mini=min(mini,vec[j][i]);
            while(mini--){
                string s(1,i+'a');
                result.push_back(s);
            }
        }
        return result;
    }
};
