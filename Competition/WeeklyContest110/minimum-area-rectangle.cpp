//https://leetcode.com/contest/weekly-contest-110/problems/minimum-area-rectangle/


class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int area=INT_MAX;
        map<int,set<int>> hmap;
        
        
        for(int i=0;i<points.size();i++){
            hmap[points[i][0]].insert(points[i][1]);
        }
        
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                int x1=points[i][0];
                int x2=points[j][0];
                int y1=points[i][1];
                int y2=points[j][1];
                
                if(x1==x2 || y1==y2) continue;
                
                if(hmap[x1].find(y2)!=hmap[x1].end() && hmap[x2].find(y1)!=hmap[x2].end())
                    area=min(area,abs(x2-x1)*abs(y2-y1));
            }
        }
        if(area==INT_MAX) return 0;
        return area;
    }
};
