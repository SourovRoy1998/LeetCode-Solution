//https://leetcode.com/contest/biweekly-contest-7/problems/single-row-keyboard/


class Solution {
public:
    int calculateTime(string keyboard, string word) {
        map<char,int> hmap;
        int result=0;
        for(int i=0;i<keyboard.length();i++)
            hmap[keyboard[i]]=i;
        int curr=0;
        for(auto x : word){
            result+=abs(hmap[x]-hmap[curr]);
            curr=x;
        }
        return result;
    }
};
