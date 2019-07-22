//https://leetcode.com/problems/longest-mountain-in-array/

class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n=A.size(),result=0;
        vector<int> forward(n,1);
        vector<int> backward(n,1);
        for(int i=1;i<n;i++)
            if(A[i]>A[i-1]) forward[i]=forward[i-1]+1;
        for(int i=n-2;i>=0;i--)
            if(A[i]>A[i+1]) backward[i]=backward[i+1]+1;
        for(int i=1;i<n-1;i++)
            if(forward[i]!=1 && backward[i]!=1)
                result=max(result,forward[i-1]+backward[i+1]+1);
        return result;
    }
};
