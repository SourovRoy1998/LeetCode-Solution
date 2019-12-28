//https://leetcode.com/contest/biweekly-contest-16/problems/sum-of-mutated-array-closest-to-target/

class Solution {
public:
    int findBestValue(vector<int>& arr, int target){
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int sum=0,roll=0,diff=INT_MAX,ans=arr[n-1];
        for(int i=0;i<n;i++)
            sum+=arr[i];
        
        if(sum<=target) return arr[n-1];
        
        int temp=min(target/n,arr[0]);
        if(abs(temp*n-target)<diff){
                diff=abs(temp*n-target);
                ans=temp;
        }
        
        temp=min(target/n+1,arr[0]);
        if(abs(temp*n-target)<diff){
                diff=abs(temp*n-target);
                ans=temp;
        }
        
        for(int i=0;i<n-1;i++){
            roll+=arr[i];
            int tempo=(target-roll)/(n-i-1);
            
            int temp=min(tempo,arr[i+1]);
            if(temp<arr[i]) continue;
            if(abs(roll+temp*(n-i-1)-target)<diff){
                diff=abs(roll+temp*(n-i-1)-target);
                ans=temp;
            }
            temp=min(tempo+1,arr[i+1]);
            if(temp<arr[i]) continue;
            if(abs(roll+temp*(n-i-1)-target)<diff){
                diff=abs(roll+temp*(n-i-1)-target);
                ans=temp;
            }
            
        }
        return ans;
    }
};
