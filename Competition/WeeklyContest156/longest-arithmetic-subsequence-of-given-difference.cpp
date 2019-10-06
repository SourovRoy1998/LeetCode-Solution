//https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        map<int, int> hmap;
        int ans=1;
        for(auto x : arr){ 
            if(hmap.find(x-diff)!=hmap.end()){
                hmap[x]=hmap[x-diff]+1;
                ans=max(ans,hmap[x]);
            }
            else hmap[x]=1;
        }
        return ans;
                
    }
};
