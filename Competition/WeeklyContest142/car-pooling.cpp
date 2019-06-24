//https://leetcode.com/problems/car-pooling/

class Solution {
public:
    static bool comp(vector<int> v1, vector<int> v2){
        return v1[1]<v2[1];
    }
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(),trips.end(),comp);
        vector<bool> down(trips.size(),false);
        
        int current_passenger=0;
        
        
        for(int i=0;i<trips.size(); i++){
            current_passenger+=trips[i][0];
            if(i!=0){
                for(int j=0;j<i;j++)
                    if(down[j]==false && trips[i][1]>=trips[j][2]){
                        current_passenger-=trips[j][0];
                        down[j]=true;
                }
            }
            if(current_passenger>capacity)
                return false;
        }
        
        return true;
    }
};
