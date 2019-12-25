//https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        multiset<int> S;
        for(auto x: nums)
            S.insert(x);
        while(!S.empty()){
            int h=*S.begin();
            //cout<<h<<endl;
            S.erase(S.begin());
            for(int i=1;i<k;i++){
                if(S.find(h+i)==S.end())
                    return false;
                S.erase(S.find(h+i));
            }
        }
        return true;
    }
};
