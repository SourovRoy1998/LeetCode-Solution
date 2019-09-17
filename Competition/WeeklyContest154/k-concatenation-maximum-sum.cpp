##https://leetcode.com/problems/k-concatenation-maximum-sum/

class Solution:
    def kConcatenationMaxSum(self,arr, k):
        if not arr or k < 1: return 0
        n = len(arr)
        curr_sum = 0
        max_sum = float('-inf')

        for i in range(n*min(k, 2)):
            curr_sum += arr[i%n]
            max_sum = max(max_sum, curr_sum)
            curr_sum = max(curr_sum, 0)
        if k > 2:
            max_sum += max((k-2)*sum(arr), 0)
            
        if(max_sum<0): return 0
        return max_sum%1000000007
        
            
            
'''
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long result=0, curr=0, sum=0;
        int mod=1e9+7;
        for(int i=0;i<arr.size();i++){
            curr=max(curr+arr[i],(long)arr[i]);
            result=max(result,curr);
            sum+=arr[i];
        }
        if(k<2) return result%mod;
        if(sum>0) return (result+sum*(k-1))%mod;
        for(int i=0;i<arr.size();i++){
            curr=max(curr+arr[i],(long)arr[i]);
            result=max(result,curr);
        }
        return result%mod;        
    }
};
'''
