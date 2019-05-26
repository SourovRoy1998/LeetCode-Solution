//https://leetcode.com/problems/distant-barcodes/

class Solution {
public:
    struct CompareByFirst {
    constexpr bool operator()(pair<int, int> const & a,
                              pair<int, int> const & b) const noexcept
    { return a.second < b.second; }
    };
    
    
    
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        priority_queue<pair<int, int>,
                   std::vector<pair<int, int> >,
                   CompareByFirst> p;
        
        
        vector<int> res;
        
        map<int,int> hmap;
        for(auto x: barcodes)
            hmap[x]++;
        for(auto &[k,v]:hmap)
            p.push({k,v});
        
        
        while(!p.empty()){
            pair<int,int> temp=p.top();
            p.pop();
            
            
            if(res.empty() || temp.first!=res.back()){
                res.push_back(temp.first);
                temp.second--;
                if(temp.second)
                    p.push(temp);
            }
            
            else{
                pair<int,int> temp2=p.top();
                p.pop();
                p.push(temp);
                
                res.push_back(temp2.first);
                temp2.second--;
                if(temp2.second)
                    p.push(temp2);
            }
            
        }
        return res;
    }
};
