//https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums[0]==0 && nums.size()>1) return false;
        int farthest=nums[0];
        for(int i=1;i<nums.size();i++){
            if(farthest<i) return false;
            farthest=max(farthest,i+nums[i]);
        }
        return true;
            
    }
};
