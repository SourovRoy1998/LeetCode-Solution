##https://leetcode.com/problems/diet-plan-performance/

class Solution:
    def dietPlanPerformance(self, calories: List[int], k: int, lower: int, upper: int) -> int:
        point=0
        T=sum(calories[:k])
        if T>upper:point+=1
        if T<lower:point-=1
        for i in range(k,len(calories)):
            T+=calories[i]
            T-=calories[i-k]
            if T>upper:point+=1
            if T<lower:point-=1
        return point
        
