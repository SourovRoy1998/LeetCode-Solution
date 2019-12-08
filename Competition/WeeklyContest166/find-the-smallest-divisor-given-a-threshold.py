##https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

import math
def f(nums,k):
    Nums=nums[:]
    for i in range(len(nums)):
        Nums[i]=math.ceil((nums[i]/k))
    return sum(Nums)
    
class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        S=sum(nums)
        k=max(1,math.floor(S/threshold))
        ans=float("inf")
        l,r=1,1000000
        
        while(l<=r):
            k=(l+r)//2
            if f(nums,k)<=threshold:
                #print(l,r,nums,k,f(nums,k))
                ans=min(k,ans)
                r=k-1
            else:
                l=k+1
        return ans
