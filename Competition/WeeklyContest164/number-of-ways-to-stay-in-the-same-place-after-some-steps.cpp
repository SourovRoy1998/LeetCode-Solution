//https://leetcode.com/contest/weekly-contest-164/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/

import functools
@functools.lru_cache(maxsize=None)
def helper(steps, arrLen, loc):
    if arrLen==1: return 1
    if arrLen<=0 or loc<1 or loc>arrLen or steps<0: return 0
    print(steps, arrLen, loc)
    return helper(steps-2,loc-1,1)+helper(steps-2,arrLen-loc,1)+helper(steps-1,arrLen,loc) 

class Solution:
    def numWays(self, steps, arrLen):
        return helper(steps, arrLen, 1)
        
