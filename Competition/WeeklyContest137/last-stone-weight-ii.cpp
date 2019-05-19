//https://leetcode.com/problems/last-stone-weight-ii/

class Solution {
public:
    static bool comp(int a,int b){
        return a>b;
    }
    
    int lastStoneWeightII(vector<int>& stones) {
        sort(stones.begin(),stones.end());
        int minimum=INT_MAX;
        int count=0;
        while(count<100000){
            count++;
            int curr=0;
            for(int i=0;i<stones.size();i++)
                curr=abs(curr-stones[i]);
            minimum=min(minimum,curr);
            random_shuffle(stones.begin(),stones.end());
        }
        return minimum;
    }
};
