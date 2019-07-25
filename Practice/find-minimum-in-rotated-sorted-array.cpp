//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if(nums[0]<nums[n-1]) return nums[0];
        
        int start=0,end=n-1,mid;
        
        while(start<end){
            if(start==end-1) return min(nums[start],nums[end]);
            mid=(start+end)/2;
            if(nums[start]>nums[mid])
                end=mid;
            else if(nums[mid]>nums[end])
                start=mid;
        }
        
        return nums[start];
    }
};
