//https://leetcode.com/contest/weekly-contest-164/problems/minimum-time-visiting-all-points/

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int result=0;
        int p=points[0][0], q=points[0][1];
        for(int i=1; i<points.size();i++){
            int r=points[i][0], s=points[i][1];
            result+=(max(abs(p-r),abs(q-s)));
            p=r;
            q=s;
        }
        return result;
    }
};
