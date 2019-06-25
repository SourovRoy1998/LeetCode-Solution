//https://leetcode.com/problems/word-pattern/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        stringstream ss(str);
        string input;
        unordered_map<char,string> hmap;
        int i=0;
            
        while(getline(ss,input,' ')){
            if(hmap.find(pattern[i])!=hmap.end())
                if(hmap[pattern[i]]!=input)
                    return false;
            hmap[pattern[i]]=input;
            i++;
        }
        if(i!=pattern.length())
            return false;
        
        stringstream ss2(str);
        string input2;
        unordered_map<string,char> hmap1;
        i=0;
            
        while(getline(ss2,input2,' ')){
            if(hmap1.find(input2)!=hmap1.end())
                if(hmap1[input2]!=pattern[i])
                    return false;
            hmap1[input2]=pattern[i];
            i++;
        }
        
        return true;
    }
};
