##https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/

class Solution:
    def groupThePeople(self, Sizes: List[int]) -> List[List[int]]:
        d=dict()
        for i in range(len(Sizes)):
            if Sizes[i] not in d.keys():
                d[Sizes[i]]=[[i]]
            else:
                if len(d[Sizes[i]][-1])<Sizes[i]:
                    d[Sizes[i]][-1].append(i)
                else:
                    d[Sizes[i]].append([i])
        result=[]
        for x in d.values():
            for y in x:
                result.append(y)
        return result
                
