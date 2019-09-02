//https://leetcode.com/problems/find-the-town-judge/


class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int n=trust.size();
        vector<int> Count(N+1,0);
        for(int i=0;i<n;i++){
            Count[trust[i][0]]--;
            Count[trust[i][1]]++;
        }
        for(int i=1;i<=N;i++)
            if(Count[i]==N-1) return i;
        return -1;
    }
};
