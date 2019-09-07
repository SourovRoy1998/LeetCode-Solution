//https://leetcode.com/problems/shortest-distance-to-target-color/


class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n=colors.size();
        vector<vector<int>> result(n, vector<int>(3,INT_MAX));
        result[0][colors[0]-1]=0;
        for(int i=1;i<n;i++){
            if(result[i-1][0]!=INT_MAX) result[i][0]=result[i-1][0]+1;
            if(result[i-1][1]!=INT_MAX) result[i][1]=result[i-1][1]+1;
            if(result[i-1][2]!=INT_MAX) result[i][2]=result[i-1][2]+1;
            result[i][colors[i]-1]=0;
        }
        result[n-1][colors[n-1]-1]=0;
        for(int i=n-2;i>=0;i--){
            if(result[i+1][0]!=INT_MAX) result[i][0]=min(result[i][0], result[i+1][0]+1);
            if(result[i+1][1]!=INT_MAX) result[i][1]=min(result[i][1], result[i+1][1]+1);
            if(result[i+1][2]!=INT_MAX) result[i][2]=min(result[i][2], result[i+1][2]+1);
            result[i][colors[i]-1]=0;
        }
        
        vector<int> answer(queries.size());
        for(int i=0;i<queries.size();i++){
            answer[i]=result[queries[i][0]][queries[i][1]-1];
            if(answer[i]==INT_MAX) answer[i]=-1;
        }
        return answer;
        
    }
};
