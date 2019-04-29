//https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> hmap;
        for(int i=0;i<nums.size();i++)
            hmap[nums[i]]=i;
        for(int i=0;i<nums.size();i++)
            if(hmap.find(target-nums[i])!=hmap.end() && i!=hmap[target-nums[i]])
                return {i,hmap[target-nums[i]]};
        
        return {5,6};
    }
};
