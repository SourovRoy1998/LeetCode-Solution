//https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/



class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        for(int i=1;i<A.size();i++)
            A[i]+=A[i-1];
        int result=A[L+M-1],LMax=A[L-1],MMax=A[M-1];
        for(int i=L+M;i<A.size();i++){
            LMax=max(LMax,A[i-M]-A[i-L-M]);
            MMax=max(MMax,A[i-L]-A[i-L-M]);
            result=max(result,max(LMax+A[i]-A[i-M],MMax+A[i]-A[i-L]));
        }
        return result;
    }
};
