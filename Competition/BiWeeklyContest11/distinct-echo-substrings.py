##https://leetcode.com/problems/distinct-echo-substrings/

class Solution:
    def distinctEchoSubstrings(self, text: str) -> int:
        s,n=set(),len(text)
        def valid(s):
            l=len(s)
            if l%2==0 and s[:l//2]==s[l//2:]:
                return True
            return False
        for i in range(n):
            for j in range(i+1,n+1):
                if valid(text[i:j]):
                    s.add(text[i:j])
        return len(s)
