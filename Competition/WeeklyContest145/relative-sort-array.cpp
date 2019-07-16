//https://leetcode.com/problems/relative-sort-array/

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> hmap;
        for(auto x:arr2)
            hmap[x]=1;
        vector<int> append,result;
        for(auto x: arr1){
            if(hmap.find(x)!=hmap.end())
                hmap[x]++;
            else
                append.push_back(x);
        }
        sort(append.begin(),append.end());
        
        for(auto x: arr2){
            while(hmap[x]!=1){
                result.push_back(x);
                hmap[x]--;
            }
        }
        
        result.insert(result.end(),append.begin(),append.end());
        
        return result;
    }
};
