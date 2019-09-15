//https://leetcode.com/problems/maximum-number-of-balloons/


class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int> hmap;
        for(auto x : text)
            hmap[x]++;
        int mini=INT_MAX;
        mini=min(mini,hmap['b']);
        mini=min(mini,hmap['a']);
        mini=min(mini,hmap['l']/2);
        mini=min(mini,hmap['o']/2);
        mini=min(mini,hmap['n']);
        
        return mini;
    }
};
