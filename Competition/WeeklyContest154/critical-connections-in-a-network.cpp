//https://leetcode.com/problems/critical-connections-in-a-network/


    class Solution {
public:
    void dfs(int node, vector<bool>& visited, vector<int>& disc,vector<int>& low, int parent,int& time,vector<vector<int>>& adj, vector<vector<int>>& result) 
{ 
    // Mark the current node as visited 
    visited[node] = true; 
  
    // Initialize discovery time and low value 
    disc[node] = low[node] = ++time; 
  
    // Go through all vertices aadjacent to this 
    for (auto curNode : adj[node]) 
    { 
        // If v is not visited yet, then recur for it 
        if (!visited[curNode]) 
        { 
            dfs(curNode,visited,disc,low,node,time,adj,result); 
            
            // Check if the subtree rooted with v has a  
            // connection to one of the ancestors of u 
            low[node]  = min(low[node], low[curNode]); 
  
            // If the lowest vertex reachable from subtree  
            // under v is  below u in DFS tree, then u-v  
            // is a bridge 
            if (low[curNode] > disc[node]) 
            {
                result.push_back({node,curNode});
            }
        } 
  
        // Update low value of u for parent function calls. 
        else if (curNode != parent) 
            low[node]  = min(low[node], disc[curNode]); 
    } 
} 

vector<vector<int>> critConnections(int Nodes, vector<vector<int>>& edges)
{
    vector<vector<int>> adj(Nodes+1,vector<int>());
    vector<int> low(Nodes+1,-1);
    vector<int> disc(Nodes+1,-1);
    vector<bool> visited(Nodes+1,false);
    vector<vector<int>> result;
    int time = 0;
    //build the adj list
    for(auto x:edges)
    {
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }
    
    for(int x=1;x<=Nodes;x++)
    {
        if(!visited[x])
        {
            dfs(x,visited,disc,low,0,time,adj,result);
        }
    }
    return result;
    
}


    
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        return critConnections(n,connections);
    }
};
