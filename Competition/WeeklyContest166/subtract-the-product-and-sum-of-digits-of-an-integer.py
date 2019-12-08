##https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/

class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        p,s=1,0
        for x in str(n):
            p*=int(x)
            s+=int(x)
        return p-s
