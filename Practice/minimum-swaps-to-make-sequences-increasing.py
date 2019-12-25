
###https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/
class Solution:
    def minSwap(self, A, B):
        noswap,swap=0,1
        
        for i in range(1,len(A)):
            if A[i-1]>=A[i] or B[i-1]>=B[i]:
                swap,noswap=noswap+1,swap
            elif max(A[i-1],B[i-1])<min(A[i],B[i]):
                swap,noswap=min(swap,noswap)+1,min(swap,noswap)
            else:
                swap,noswap=swap+1,noswap
        return min(swap,noswap)
