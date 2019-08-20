//https://leetcode.com/problems/guess-number-higher-or-lower/



// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int start=1,end=n,mid;
        
        while(true){
            mid=start+(end-start)/2;
            if(guess(mid)==0) return mid;
            if(guess(mid)==-1) end=mid-1;
            if(guess(mid)==1) start=mid+1;
        }
    }
};
