//https://leetcode.com/problems/minimum-moves-to-equal-array-elements/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        long int n=nums.size(), mini=INT_MAX, sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(mini>nums[i]) mini=nums[i];
        }
        return sum-mini*n;
    }
};
