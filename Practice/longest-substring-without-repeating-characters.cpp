//https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0,result=0;
        set<char> repeated;
        while(j<s.length()){
            if(repeated.find(s[j])!=repeated.end()){
                while(s[i]!=s[j]){repeated.erase(s[i]); i++;}
                i++;
            }
            result=max(result,j-i+1);
            repeated.insert(s[j]);
            j++;
        }
        return result;
    }
};
