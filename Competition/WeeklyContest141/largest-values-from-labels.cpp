//https://leetcode.com/problems/largest-values-from-labels/

class Solution {
public:
    static bool comp(vector<int> a, vector<int> b){
        return a[1]>b[1];
    }
    
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        vector<vector<int>> vec(values.size());
        for(int i=0;i<values.size();i++){
            vec[i].push_back(labels[i]);
            vec[i].push_back(values[i]);
        }
        sort(vec.begin(),vec.end(),comp);
        map<int,int> hmap;
        for(auto x: labels)
            hmap[x]=use_limit;
    
        int result=0;
        for(auto x: vec){
            if(num_wanted==0)
                return result;
            if(hmap[x[0]]!=0){
                result+=x[1];
                hmap[x[0]]--;
                num_wanted--;
            }
        }
    
        return result;
    }
    
};
