//https://leetcode.com/contest/biweekly-contest-16/problems/replace-elements-with-greatest-element-on-right-side/

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        vector<int> result(n,-1);
        for(int i=n-2;i>=0;i--)
            result[i]=max(arr[i+1],result[i+1]);
        return result;
    }
};
