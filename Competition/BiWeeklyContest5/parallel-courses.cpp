//https://leetcode.com/contest/biweekly-contest-5/problems/parallel-courses/

class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        vector<int> prereq_num(N+1,0);
        int ans=0;
        vector<vector<int>> can_do(N+1);
        for(auto x : relations){
            can_do[x[0]].push_back(x[1]);
            prereq_num[x[1]]++;
        }
        
        queue<int> Q;
        for(int i=1;i<=N;i++)
            if(prereq_num[i]==0) Q.push(i);
        
        while(!Q.empty()){
            int n=Q.size();
            ans++;
            for(int i=0;i<n;i++){
                int e=Q.front(); Q.pop();
                for(auto x : can_do[e])
                    if(--prereq_num[x]==0)
                        Q.push(x);
            }
        }
        
        for(int i=1; i<=N; i++) if(prereq_num[i]>0) return -1;
        return ans;
                
            
    }
};
