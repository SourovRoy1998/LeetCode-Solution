//https://leetcode.com/problems/moving-stones-until-consecutive/

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int x=min(a,min(b,c));
        int z=max(a,max(b,c));
        int y=a^b^c^x^z;
        
        int maxi = z-x-2;
        int mini = min(maxi,(z-y<=2 || y-x<=2 ? 1 : 2));
        
        return {mini,maxi};
    }
};
