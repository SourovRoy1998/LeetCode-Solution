##https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

class Solution:
    def smallestSubsequence(self, S: str) -> str:
        last={}
        for x,y in enumerate(S):
            last[y]=x;
        result=""
        left=0
        while last:
            right=min(last.values())
            c,i=min((S[i],i) for i in range(left,right+1) if S[i] not in result)
            left=i+1
            result+=c
            if c in last:
                del last[c]
        return result
        
        
