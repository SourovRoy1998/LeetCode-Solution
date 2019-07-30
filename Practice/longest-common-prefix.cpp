//https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {  
        if(strs.empty()) return "";
        int p=strs[0].length(),j;
        for(int i=1;i<strs.size();i++){
            j=0;
            while(j<p && j<strs[i].length() && strs[i][j]==strs[0][j]){
                j++;
            }
            p=min(j,p);
        }
        return strs[0].substr(0,p);
    }
};
