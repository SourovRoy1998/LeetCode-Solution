https://leetcode.com/problems/number-of-equivalent-domino-pairs/

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int>,int> hmap;
        for(auto x: dominoes)
            hmap[{x[0],x[1]}]++;
        
        int result=0;
        for(auto x: dominoes){
            result+=(hmap[{x[0],x[1]}]-1);
            
            if(hmap.find({x[1],x[0]})!=hmap.end() && x[1]!=x[0])
                result+=hmap[{x[1],x[0]}];
        }
        return result/2;
    }
};
