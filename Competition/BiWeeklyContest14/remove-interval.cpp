//https://leetcode.com/contest/biweekly-contest-14/problems/remove-interval/

class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& R) {
        vector<vector<int>> result;
        for(auto x : intervals){
            if(x[0]<=R[0] && x[1]<=R[0])
                result.push_back(x);
            else if(x[0]>=R[1] && x[1]>=R[1])
                result.push_back(x);
            else if(x[0]>=R[0] && x[1]<=R[1])
                continue;
            else if(x[0]<=R[0] && x[1]<=R[1])
                    result.push_back({x[0],R[0]});
            else if(x[0]>=R[0] && x[1]>=R[1])
                    result.push_back({R[1],x[1]});
            else if(x[0]<=R[0] && x[1]>=R[1]){
                    result.push_back({x[0],R[0]});
                    result.push_back({R[1],x[1]});
            }
        }
        return result; 
    }
};
