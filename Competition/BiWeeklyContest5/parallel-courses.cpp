//https://leetcode.com/contest/biweekly-contest-5/problems/parallel-courses/

//Do It Yourself


//Sol 1

class Solution {

private:
    
    map<int,int> depends;
    map<int,vector<int>> dependents; 
    int ans;
    int terms;
    queue<int> Q;
    
    void topo() { 
        while(!Q.empty()) {
            int x = Q.front();
            Q.pop();
            
            if(x == NULL) {
                terms++;
                if(!Q.empty()) {
                    Q.push(NULL);
                }
                continue;
            }
            
            ans++;
        
            for(int i=0;i<dependents[x].size();i++) { 
                depends[dependents[x][i]]--;
                if(depends[dependents[x][i]]==0)
                    Q.push(dependents[x][i]);
            }
        } // while
    }
    
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        for(auto relation : relations) {
            // Y depends on X
            int X = relation[0];
            int Y = relation[1];
            
            depends[Y]++;
            dependents[X].push_back(Y);
        }
        
        for(int i=1;i<=N;i++)
            if(depends[i]==0)
                Q.push(i);
        
        Q.push(NULL); // for term end
        
        ans = 0;
        terms = 0;
        topo();
        
        if(ans!=N) {
            terms = -1; // not possible
        }
        
        return terms;
    }
};
















//Sol 2
const int inf = 10000000;

class Solution {
    vector<vector<int>> G;
    vector<int> ans;
    
    int dfs(int v) {
        if (ans[v] < 0) {
            ans[v] = inf;
        }
        
        if (ans[v]) return ans[v];
        ans[v] = -1;
        int r = 0;
        for (int x: G[v]) {
            r = max(r, dfs(x));
        }
        
        ans[v] = r + 1;
        return ans[v];
    }
    
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        G.resize(N + 1);
        ans.resize(N + 1);
        for (auto &x: relations)
            G[x[0]].push_back(x[1]);
        
        int ret = 0;
        for (int i = 1; i <= N; i++)
            ret = max(ret, dfs(i));
        
        if (ret >= inf) ret = -1;
        return ret;
    }
};








//Sol 3

class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        vector<int> indegree(N + 1, 0);
        unordered_map<int, vector<int>> adj;
        for (auto x : relations) {
            ++indegree[x[1]];
            adj[x[0]].push_back(x[1]);
        }
        queue<int> q;
        for (int i = 1; i <= N; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        int res = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                int cur = q.front();
                q.pop();
                --N;
                for (auto& nei : adj[cur]) {
                    if (--indegree[nei] == 0) {
                        q.push(nei);
                    }
                }
            }
            ++res;
        }
        return N == 0 ? res : -1;
    }
};


//Sol 4

class Solution:
    def minimumSemesters(self, n: int, r: List[List[int]]) -> int:
        post = [[] for i in range(n + 1)]
        pre = [set() for i in range(n + 1)]
        cand = set(range(1, n + 1))
        for u, v in r:
            post[u].append(v)
            pre[v].add(u)
            cand.discard(v)
        s = 0
        taken = set()
        while cand:
            s += 1
            nc = set()
            taken |= cand
            for i in cand.copy():
                for j in post[i]:
                    pre[j].discard(i)
                    if not pre[j]:
                        nc.add(j)
            cand = nc
        return s if len(taken) == n else -1


