##https://leetcode.com/problems/delete-tree-nodes/

class Solution:
    def deleteTreeNodes(self, n, parent, value):
        sons = {i: set() for i in range(n)}
        for i, p in enumerate(parent):
            if i: sons[p].add(i)

        def dfs(x):
            total, count = value[x], 1
            for y in sons[x]:
                t, c = dfs(y)
                total += t
                count += c if t else 0
            return total, count if total else 0
        return dfs(0)[1]
