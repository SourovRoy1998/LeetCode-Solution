//https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==0)
            return {};
        if(numRows==1)
            return {{1}};
        vector<vector<int>> result;
        result.push_back({1});
        result.push_back({1,1});
        if(numRows==2)
            return result;
        for(int i=3;i<=numRows;i++){
            vector<int> curr;
            curr.push_back(1);
            for(int j=0;j<i-2;j++)
                curr.push_back(result.back()[j]+result.back()[j+1]);
            curr.push_back(1);
            result.push_back(curr);
        }
        return result;
    }
};
