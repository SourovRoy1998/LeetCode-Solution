#https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together/

class Solution:
    def minSwaps(self, data: List[int]) -> int:
        cnt = sum(data)
        MAX = m = sum(data[0:cnt])
        for i in range(cnt, len(data)):
            m += data[i] - data[i - cnt]
            MAX = max(MAX, m)
        return cnt - MAX
        
