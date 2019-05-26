//https://leetcode.com/problems/combination-sum/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target, int level=0) {
        if(target==0)
            return {{}};
        vector<vector<int>> res;
        for(int i=level;i<candidates.size();i++){
            if(target<candidates[i])
                continue;
            for(vector<int> &b:combinationSum(candidates,target-candidates[i],i)){
                b.push_back(candidates[i]);
                res.push_back(b);
            }
        }
        return res;
    }
};
