//https://leetcode.com/problems/custom-sort-string/

class Solution {
public:
    string customSortString(string S, string T) {
        unordered_map<char,int> hmap;
        for(int i=0;i<T.length();i++)
            hmap[T[i]]+=1;
        string ans="";
        for(int i=0;i<S.length();i++)
            if(hmap.find(S[i])!=hmap.end()){
                for(int j=0;j<hmap[S[i]];j++)
                    ans+=S[i];
                hmap.erase(S[i]);
            }
        for(auto& [k,v]:hmap)
            for(int j=0;j<v;j++)
                ans+=k;
        return ans;
            
        
        
    }
};
