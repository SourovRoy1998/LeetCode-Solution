//https://leetcode.com/problems/play-with-chips/

class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int even=0,odd=0;
        for(auto x : chips){
            if(x%2) odd++;
            else even++;
        }
        return min(even,odd);
    }
};
