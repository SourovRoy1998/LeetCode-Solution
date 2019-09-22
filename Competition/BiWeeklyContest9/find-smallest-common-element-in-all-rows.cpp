//https://leetcode.com/contest/biweekly-contest-9/problems/find-smallest-common-element-in-all-rows/

class Solution {
public:
    int findCommon(vector<vector<int>> mat){ 
        int M=mat.size(),N=mat[0].size();
        unordered_map<int, int> cnt; 
        int i, j; 
        for (i = 0; i < M; i++) { 
            cnt[mat[i][0]]++; 
            for (j = 1; j < N; j++) { 
                if (mat[i][j] != mat[i][j - 1]) 
                    cnt[mat[i][j]]++; 
            } 
        } 
        int ans=-1;
        for (auto ele : cnt) { 
            if (ele.second == M) 
                ans=ele.first; 
        } 
        return ans; 
    }   
    int smallestCommonElement(vector<vector<int>>& mat) {
        return findCommon(mat);
    }
};
