//https://leetcode.com/problems/decrease-elements-to-make-array-zigzag/

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        if(nums.size()<3) return 0;
        
        int answer1=0,answer2=max(0,(nums[0]-nums[1]+1));
        for(int i=1;i<nums.size()-1;i+=2)
            answer1+=max(0,(nums[i]-min(nums[i-1],nums[i+1])+1));
        for(int i=2;i<nums.size()-1;i+=2)
            answer2+=max(0,(nums[i]-min(nums[i-1],nums[i+1])+1));
        if(nums.size()%2) answer2+=max(0,(nums[nums.size()-1]-nums[nums.size()-2]+1));
        if(nums.size()%2==0) answer1+=max(0,(nums[nums.size()-1]-nums[nums.size()-2]+1));
        return min(answer1,answer2);
    }
};
