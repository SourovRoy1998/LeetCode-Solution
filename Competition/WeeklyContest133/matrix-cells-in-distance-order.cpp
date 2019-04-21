//https://leetcode.com/contest/weekly-contest-133/problems/matrix-cells-in-distance-order/


int r1,c1;
class Solution {
public:
    static bool compare(const vector<int>& v1, const vector<int>& v2){
        return (abs(v1[0]-r1)+abs(v1[1]-c1)) < (abs(v2[0]-r1)+abs(v2[1]-c1));
    }
    
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> result;
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++){
                result.push_back({i,j});
            }
        r1=r0;
        c1=c0; 
        
        sort(result.begin(), result.end(), compare);
        return result;
    }
    
 
   
};
