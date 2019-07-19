//https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/

class Solution {
public:
    int gcd(int x1, int x2){
        if(x1<x2) swap(x1,x2);
        if(x2==0) return x1;
        return gcd(x2,x1%x2);
    }
    
    
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> hmap;
        for(auto x: deck)
            hmap[x]++;
        int gcd_val=hmap[deck[0]];
        for(auto &[k,v]:hmap){
            gcd_val=gcd(gcd_val,v);
        }
        
        cout<<gcd(2,2)<<endl;
        return gcd_val>=2; 
    }
};
