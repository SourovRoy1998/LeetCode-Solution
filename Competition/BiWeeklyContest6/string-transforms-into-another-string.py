##https://leetcode.com/problems/string-transforms-into-another-string/

class Solution:
    def canConvert(self, s1, s2):
        if s1 == s2: return True
        dp = {}
        for i, j in zip(s1, s2):
            if dp.setdefault(i, j) != j:
                return False
        return len(set(dp.values())) < 26
