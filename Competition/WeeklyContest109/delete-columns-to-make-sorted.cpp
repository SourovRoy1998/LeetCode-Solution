//https://leetcode.com/problems/delete-columns-to-make-sorted/

class Solution {
public:
    bool issorted(vector<string>& A,int x){
        for(int i=1;i<A.size();i++){
            if(A[i][x]<A[i-1][x]) return false;
        }
        return true;
    } 
    
    int minDeletionSize(vector<string>& A) {
        int count=0;
        for(int i=0;i<A[0].length();i++)
            if(! issorted(A,i)) count++;
        return count;
    }
};
