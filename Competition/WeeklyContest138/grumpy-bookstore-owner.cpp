//https://leetcode.com/problems/grumpy-bookstore-owner/

class Solution {
public:
    int maxSum(int arr[], int n, int k) { 
    if (n < k)
        k=n;
    int res = 0; 
    for (int i=0; i<k; i++) 
       res += arr[i]; 
    int curr_sum = res; 
    for (int i=k; i<n; i++) { 
       curr_sum += arr[i] - arr[i-k]; 
       res = max(res, curr_sum); 
        } 
    return res; 
    } 
    
    
    
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int ans=0;
        int new_vector[grumpy.size()];
        for(int i=0;i<grumpy.size();i++){
            if(grumpy[i]==0)
                ans+=customers[i];
            new_vector[i]=customers[i]*grumpy[i];
            }
        ans+=maxSum(new_vector,grumpy.size(),X);
        return ans;
    }
};
