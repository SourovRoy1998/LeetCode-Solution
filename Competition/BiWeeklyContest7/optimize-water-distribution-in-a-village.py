//https://leetcode.com/problems/optimize-water-distribution-in-a-village/

class Solution:
    def minCostToSupplyWater(self, n, wells, pipes):
        UF = {i: i for i in xrange(n + 1)}

        def find(x):
            if x != UF[x]:
                UF[x] = find(UF[x])
            return UF[x]

        def union(x, y):
            UF[find(x)] = find(y)

        w = [[c, 0, i] for i, c in enumerate(wells, 1)]
        p = [[c, i, j] for i, j, c in pipes]
        res = 0

        for c, i, j in sorted(w + p):
            if find(i) != find(j):
                union(i, j)
                res += c
                n -= 1
            if n == 0:
                return res
        return -1
        
