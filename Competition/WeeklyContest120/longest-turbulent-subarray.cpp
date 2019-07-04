//https://leetcode.com/problems/longest-turbulent-subarray/


class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int ans=1;
        int temp=1;
        for(int i=0;i<A.size()-1;i++){
            if(i%2==0 && A[i+1]>A[i]) temp++;
            else if(i%2==1 && A[i+1]<A[i]) temp++;
            else temp=1;
            ans=max(ans,temp);
        }
        temp=1;
        for(int i=0;i<A.size()-1;i++){
            if(i%2==1 && A[i+1]>A[i]) temp++;
            else if(i%2==0 && A[i+1]<A[i]) temp++;
            else temp=1;
            ans=max(ans,temp);
        }
        
        return ans;
    }
};
