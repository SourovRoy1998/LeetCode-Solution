//https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int>result(seq.size());
        for(int i=0;i<seq.size();i++)
            result[i]=(i&1)^(seq[i]=='(');
        return result;
    }
};
