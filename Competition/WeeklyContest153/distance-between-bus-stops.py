##https://leetcode.com/problems/distance-between-bus-stops/

class Solution:
    def distanceBetweenBusStops(self, distance: List[int], start: int, destination: int) -> int:
        s=sum(distance)
        x=min(start,destination)
        y=max(start,destination)
        s1=sum(distance[x:y])
        return min(s1,s-s1)
