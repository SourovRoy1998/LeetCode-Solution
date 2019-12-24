###https://leetcode.com/problems/find-numbers-with-even-number-of-digits/

class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        count=0
        for x in nums:
            if len(str(x))%2==0:
                count+=1
        return count
