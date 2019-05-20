//https://leetcode.com/problems/k-closest-points-to-origin/

class Solution {
public:
    static bool comp(vector<int> a, vector<int> b){
        return sqrt(a[0]*a[0]+a[1]*a[1])<sqrt(b[0]*b[0]+b[1]*b[1]);
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(),points.end(),comp);
        vector<vector<int>> answer;
        for(int i=0;i<K;i++)
            answer.push_back(points[i]);
        return answer;
    }
};
