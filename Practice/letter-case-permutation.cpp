//https://leetcode.com/problems/letter-case-permutation/

class Solution {
public:
    vector<string> helper(string S){
        if(S.empty()) return {""};
        vector<string> result;
        if(!isalpha(S[0]))
            for(auto x : helper(S.substr(1,S.length()-1)))
                result.push_back(S[0]+x);
        else
            for(auto x : helper(S.substr(1,S.length()-1))){
                result.push_back((char)tolower(S[0])+x);
                result.push_back((char)toupper(S[0])+x);
            }
        return result;
    }
    vector<string> letterCasePermutation(string S) {
        if(S.empty()) return {};
        return helper(S);
    }
};
