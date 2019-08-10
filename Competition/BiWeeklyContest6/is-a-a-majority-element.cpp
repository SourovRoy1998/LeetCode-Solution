//https://leetcode.com/problems/is-a-a-majority-element/

class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        unordered_map<int,int> hmap;
        for(auto x : nums)
            hmap[x]++;
        return hmap[target]*2>nums.size();
    }
};
