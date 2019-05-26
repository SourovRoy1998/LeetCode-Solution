//https://leetcode.com/problems/height-checker/

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> heights_sort(heights);
        sort(heights.begin(),heights.end());
        int count=0;
        for(int i=0;i<heights.size();i++){
            if(heights[i]!=heights_sort[i])
                count++;
        }
        return count;
    }
};
