//https://leetcode.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> result;
        
        for(int i=0;i<n-3;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n-2;j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int k=j+1,l=n-1;
                while(k<l){
                    if(k>j+1 && nums[k]==nums[k-1]){k++; continue;}
                    if(l<n-1 && nums[l]==nums[l+1]){l--; continue;}
                    int sum=nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum==target){
                        result.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                    }
                    else if(sum<target) k++;
                    else if(sum>target) l--;
                }
            }
        }
        
        return result;
    }
};
