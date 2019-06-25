//https://leetcode.com/problems/product-of-array-except-self/


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n,0);
        
        result[0]=nums[0];
        for(int i=1;i<n-1;i++){
            result[i]=result[i-1]*nums[i];
        }
        
        int product=nums[n-1];
        result[n-1]=result[n-2];
        
        for(int i=n-2;i>0;i--){
            result[i]=result[i-1]*product;
            product*=nums[i];
        }
        
        result[0]=product;
        
        return result;
    }
};
