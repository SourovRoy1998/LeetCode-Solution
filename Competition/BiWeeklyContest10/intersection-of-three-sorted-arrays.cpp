//https://leetcode.com/contest/biweekly-contest-10/problems/intersection-of-three-sorted-arrays/

class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> result;
        map<int,int> hmap1,hmap2,hmap3;
        for(auto x: arr1) hmap1[x]++;
        for(auto x: arr2) hmap2[x]++;
        for(auto x: arr3) hmap3[x]++;
        
        for(auto [k,v]: hmap1){
            if(hmap2.find(k)!=hmap2.end() && hmap3.find(k)!=hmap3.end()){
                int c=min(hmap1[k],min(hmap2[k],hmap3[k]));
                while(c--) result.push_back(k);
            }
        }
        return result;
        
    }
};
