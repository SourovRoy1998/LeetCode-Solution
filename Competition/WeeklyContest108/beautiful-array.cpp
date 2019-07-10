//https://leetcode.com/problems/beautiful-array/

class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int> result={1};
        
        while(result.size()<N){
            vector<int> temp;
            for(auto x : result) if((2*x-1)<=N) temp.push_back(2*x-1);
            for(auto x : result) if((2*x)<=N) temp.push_back(2*x);
            result=temp;
        }
        
        return result;
    }
};
