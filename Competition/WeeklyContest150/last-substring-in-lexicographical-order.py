##https://leetcode.com/problems/last-substring-in-lexicographical-order/

##Python3 : Brute Force

class Solution:
    def lastSubstring(self, s):
        result=""
        for i in range(len(s)):
            result=max(result,s[i:])
        return result


