//https://leetcode.com/problems/letter-tile-possibilities/



class Solution {
public:
    int Possibilites(unordered_map<char,int>& hmap){
        int result=0;
        for(int i=0;i<26;i++){
            if(hmap['A'+i]!=0){
                hmap['A'+i]--;
                result+=Possibilites(hmap)+1;
                hmap['A'+i]++; 
            }
        }
        return result;
    }
    
    int numTilePossibilities(string tiles) {
        unordered_map<char,int> hmap;
        for(auto x: tiles)
            hmap[x]++;
        return Possibilites(hmap);
    }
};
