###https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/

from collections import defaultdict

class Solution:
    def maxFreq(self, s: str, maxLetters: int, minSize: int, maxSize: int) -> int:
        string_map=defaultdict(int)
        rolling_map=defaultdict(int)
        n=len(s)
        for i in range(n):
            if i<(minSize-1):
                rolling_map[s[i]]+=1
            else:
                rolling_map[s[i]]+=1
                if len(rolling_map.keys())<=maxLetters:
                    string_map[s[(i-minSize+1):(i+1)]]+=1
                if rolling_map[s[i-minSize+1]]==1:
                    del(rolling_map[s[i-minSize+1]])
                else:
                    rolling_map[s[i-minSize+1]]-=1
        if len(string_map.values())==0: return 0
        return max(string_map.values())
                
