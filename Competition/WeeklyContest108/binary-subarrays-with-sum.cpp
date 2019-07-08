//https://leetcode.com/problems/binary-subarrays-with-sum/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int n=A.size();
        vector<int> memoize(n+1,0);
        memoize[0]=1;
        int accumulator=0,result=0;
        for(auto x : A){
            accumulator+=x;
            if(accumulator>=S)
                result+=memoize[accumulator-S];
            memoize[accumulator]++;
            
        }
        
        return result;
    }
};
