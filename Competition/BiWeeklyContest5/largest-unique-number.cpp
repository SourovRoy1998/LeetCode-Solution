//https://leetcode.com/contest/biweekly-contest-5/problems/largest-unique-number/



class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        int result=INT_MIN;
        unordered_map<int,int>hmap;
        for(auto x : A)
            hmap[x]++;
        
        
        
        for(auto x : A)
            if(hmap[x]==1)
                result=max(result,x);
        
        if(result==INT_MIN) return -1;
        return result;
    }
};
