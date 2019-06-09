##https://leetcode.com/problems/letter-tile-possibilities/


class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        from itertools import permutations
        L=[]
        InpString=list(tiles)
        for r in range(1,len(InpString)+1):
            for element in permutations(InpString, r):
                L.append(element)
        return len(set(L))
        
