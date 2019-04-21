//https://leetcode.com/contest/weekly-contest-133/problems/two-city-scheduling/

class Solution {
public:
    static bool compare(vector<int> v1,vector<int> v2){
        return (v1[1]-v1[0])>(v2[1]-v2[0]);
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),compare); 

        int ans=0;
        int n=costs.size();
        for(int i=0;i<n;i++){
            if(i<n/2)
                ans=ans+costs[i][0];
            else
                ans=ans+costs[i][1];
        }
        
        return ans;
    }
};
