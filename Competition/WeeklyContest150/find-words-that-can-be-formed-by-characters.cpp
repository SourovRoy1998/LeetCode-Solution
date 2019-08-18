//https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/



class Solution {
public:
    
    bool form(string str, vector<int> hmap){
        for(auto x : str){
            if(hmap[x-'a']==0) return false;
            hmap[x-'a']--;
        }
        return true;
    }
    
    int countCharacters(vector<string>& words, string chars) {
        vector<int> hmap(26,0);
        for(auto x : chars)
            hmap[x-'a']++;
        int answer=0;
        for(auto x : words)
            if(form(x,hmap)) answer+=x.length();
        return answer;
    }
};
