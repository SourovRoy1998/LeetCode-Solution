//https://leetcode.com/problems/longest-well-performing-interval/

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        unordered_map<int,int> hmap;
        int result=0, sum=0;
        for(int i=0;i<hours.size();i++){
            sum+=hours[i]>8?1:-1;
            if(sum>0) result=i+1;
            else{
                if(hmap.find(sum)==hmap.end()) hmap[sum]=i;
                if(hmap.find(sum-1)!=hmap.end()) result=max(result,i-hmap[sum-1]);
            }
        }
        return result;
    }
};
