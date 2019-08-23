//https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,j=0,k,n=nums.size(),curr=0;
        if(n<3) return {};
        vector<vector<int>> result;
        set<vector<int>> s;
        for(int i=0;i<n-2;i++){
            j=i+1;k=n-1;
            while(j<k){
                curr=nums[i]+nums[j]+nums[k];
                if(curr==0){
                    if(s.find({nums[i],nums[j],nums[k]})==s.end())
                        result.push_back({nums[i],nums[j],nums[k]});
                    j++;k--;
                    while(j<k && nums[j-1]==nums[j]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
                else if(curr>0){
                    k--;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
                else if(curr<0){
                    j++;
                    while(j<k && nums[j-1]==nums[j]) j++;
                }
            }
            while(i<n-1 && nums[i]==nums[i+1]) i++;
        }
        return result;
    }
};
