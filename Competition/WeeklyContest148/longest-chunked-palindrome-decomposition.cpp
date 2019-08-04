//https://leetcode.com/problems/longest-chunked-palindrome-decomposition/

/*
##Python Solution
class Solution:
    def longestDecomposition(self, text: str) -> int:
        if(len(text)<=1): return len(text);
        for k in range(1,len(text)//2+1):
            if(text[:k]==text[-k:]): return self.longestDecomposition(text[k:-k])+2
        return 1;
*/

class Solution {
public:
    int longestDecomposition(string text) {
        if(text.empty()) return 0;
        int i=0,j=text.length()-1;
        int k=j,l=i;
        while(l<j && k<text.length()){
             int len=0;
             while(l<j && text[l]==text[k]){
                 len++;l++;k++;
                 if(k==text.length()) return longestDecomposition(text.substr(len,text.size()-2*len))+2;
            }
            j--;l=i;k=j;
        }
        
        return 1;
        
    }
};
