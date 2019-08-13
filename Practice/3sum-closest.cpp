//https://leetcode.com/problems/3sum-closest/


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int minDiff=INT_MAX, closeSum, threeSum, diff;
        for(int i=0;i<n-2;i++){
            int j=i+1,k=n-1;
            while(j<k){
                threeSum=nums[i]+nums[j]+nums[k];
                diff=target-threeSum;
                if(abs(diff)<minDiff){
                    minDiff=abs(diff);
                    closeSum=threeSum;
                }
                if(diff<0) k--;
                else if (diff>0) j++;
                else return closeSum;
            }
        }
        
        return closeSum;
    }
};
