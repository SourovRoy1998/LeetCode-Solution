###https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/

from collections import defaultdict
class Solution:
    def findSpecialInteger(self, arr):
        d=defaultdict(int)
        for x in arr:
            d[x]+=1
            if d[x]>(len(arr)/4):
                return x
