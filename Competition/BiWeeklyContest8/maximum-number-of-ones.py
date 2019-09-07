##https://leetcode.com/problems/maximum-number-of-ones/


class Solution:
    def maximumNumberOfOnes(self, width: int, height: int, sideLength: int, maxOnes: int) -> int:
        res = []
        for i in range(0, sideLength):
            for j in range(0, sideLength):
                res += [((width - i - 1) // sideLength + 1) * ((height - j - 1) // sideLength + 1)]
        res = sorted(res,reverse = True)
        return sum(res[:maxOnes])
