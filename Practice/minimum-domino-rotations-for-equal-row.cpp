//https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/


class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int ans=INT_MAX, n=A.size();
        for(int i=1;i<=6;i++){
            int k=0, top=0, bottom=0;
            while(k<n && (A[k]==i || B[k]==i)){
                if(A[k]!=i) top++;
                if(B[k]!=i) bottom++;
                k++;
            }
            if(k==n) ans=min(ans,min(top,bottom));
        }
        return ans==INT_MAX?-1:ans;
    }
};
