//https://leetcode.com/problems/largest-number-at-least-twice-of-others/

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxi=INT_MIN,indx;
        for(int i=0;i<nums.size();i++)
            if(nums[i]>maxi){ maxi=nums[i]; indx=i;}
        
        for(int i=0;i<nums.size();i++)
            if(indx!=i && maxi<2*nums[i]) return -1;
        return indx;
    }
};
