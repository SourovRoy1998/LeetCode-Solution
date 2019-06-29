https://leetcode.com/problems/two-sum-less-than-k/


class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        int maxi=-1;
        for(int i=0;i<A.size();i++){
            for(int j=i+1;j<A.size();j++){
                if(A[i]+A[j]<K)
                    maxi=max(maxi,A[i]+A[j]);
            }
        }
        return maxi;
    }
};
