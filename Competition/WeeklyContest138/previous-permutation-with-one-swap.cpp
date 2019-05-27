//https://leetcode.com/problems/previous-permutation-with-one-swap/

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        if(is_sorted(A.begin(),A.end())) return A;
        //swap the first peak (from right) with its later max < the peak value
        int pkind=0;
        for(int i=A.size()-2;i>=0;i--)
        {
            if(A[i]>A[i+1]) {pkind=i;break;}
        }
        for(int i=A.size()-1;i>pkind;i--) 
            if(A[pkind]>A[i]) {
			while(i>pkind && A[i]==A[i-1]) i--; //this is to get the leftmost number if they are the same.
			swap(A[i],A[pkind]);break;}
        return A;
    }
};
