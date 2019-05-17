//https://leetcode.com/problems/roman-to-integer/

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> hmap;
        hmap['I']=1;
        hmap['V']=5;
        hmap['X']=10;
        hmap['L']=50;
        hmap['C']=100;
        hmap['D']=500;
        hmap['M']=1000;
        
        int sum_upto=0;
        int i=0;
        for(i=0;i<s.length()-1;i++){
            if(hmap[s[i+1]]>hmap[s[i]])
                sum_upto-=hmap[s[i]];
            else
                sum_upto+=hmap[s[i]];
        }
        sum_upto+=hmap[s[i]];
        return sum_upto;
    }
};
