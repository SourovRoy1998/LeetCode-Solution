//https://leetcode.com/problems/find-k-length-substrings-with-no-repeated-characters/

class Solution {
public:
    int is_repeated(string s){
        map<char,int> hmap;
        for(auto x: s){
            hmap[x]++;
            if(hmap[x]>1)
                return true;
        }
        return false;
    }
    
    
    int numKLenSubstrNoRepeats(string S, int K) {
        if(K>S.length() || K>26) return 0;
        
        int count=0;
        
        for(int i=0;i<=S.length()-K;i++)
            if(!is_repeated(S.substr(i,K))) count++;
        return count;
    }
};
