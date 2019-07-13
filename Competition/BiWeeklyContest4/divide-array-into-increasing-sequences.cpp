//https://leetcode.com/contest/biweekly-contest-4/problems/divide-array-into-increasing-sequences/

class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int K) {
        map<int,int> hmap;
        int maxi=0;
        for(auto x : nums){hmap[x]++;maxi=max(maxi,hmap[x]);}
        if(nums.size()>=K*maxi) return true;
        return false;
    }
};
